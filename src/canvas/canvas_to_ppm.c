#include "minirt.h"
#include <unistd.h>

#define PPM_MAX_LINE 70

static int clamp_color_component(float value)
{
	if (value <= 0.0f)
		return (0);
	if (value >= 1.0f)
		return (255);
	return ((int)roundf(value * 255.0f));
}

static int append_int(char *buffer, int value)
{
	int length;

	length = 0;
	if (value >= 100)
	{
		buffer[length++] = (char)('0' + (value / 100));
		value %= 100;
	}
	if (length > 0 || value >= 10)
	{
		buffer[length++] = (char)('0' + (value / 10));
		value %= 10;
	}
	buffer[length++] = (char)('0' + value);
	return (length);
}

static void flush_line(int fd, char *line, int *len)
{
	if (*len <= 0)
		return ;
	write(fd, line, *len);
	write(fd, "\n", 1);
	*len = 0;
}

static void append_component(int fd, char *line, int *len, int value)
{
	char token[4];
	int token_len;
	int i;

	token_len = append_int(token, value);
	if (*len > 0 && *len + 1 + token_len > PPM_MAX_LINE)
		flush_line(fd, line, len);
	if (*len > 0)
		line[(*len)++] = ' ';
	i = 0;
	while (i < token_len)
		line[(*len)++] = token[i++];
}

static void write_ppm_header(int fd, t_canvas *canvas)
{
	char header[64];
	char number[12];
	int header_len;
	int number_len;
	int i;

	header_len = 0;
	header[header_len++] = 'P';
	header[header_len++] = '3';
	header[header_len++] = '\n';
	number_len = append_int(number, canvas->width);
	i = 0;
	while (i < number_len)
		header[header_len++] = number[i++];
	header[header_len++] = ' ';
	number_len = append_int(number, canvas->height);
	i = 0;
	while (i < number_len)
		header[header_len++] = number[i++];
	header[header_len++] = '\n';
	header[header_len++] = '2';
	header[header_len++] = '5';
	header[header_len++] = '5';
	header[header_len++] = '\n';
	write(fd, header, header_len);
}

static void write_ppm_pixels(int fd, t_canvas *canvas)
{
	char line[PPM_MAX_LINE + 1];
	int line_len;
	int x;
	int y;
	int index;
	t_color pixel;

	line_len = 0;
	y = 0;
	while (y < canvas->height)
	{
		x = 0;
		while (x < canvas->width)
		{
			index = y * canvas->width + x;
			pixel = canvas->pixels[index];
			append_component(fd, line, &line_len, clamp_color_component(pixel.red));
			append_component(fd, line, &line_len, clamp_color_component(pixel.green));
			append_component(fd, line, &line_len, clamp_color_component(pixel.blue));
			x++;
		}
		flush_line(fd, line, &line_len);
		y++;
	}
}

void canvas_to_ppm(t_canvas *canvas, char *filename)
{
	int fd;

	if (!canvas || !canvas->pixels || !filename)
		return ;
	if (canvas->width <= 0 || canvas->height <= 0)
		return ;
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	write_ppm_header(fd, canvas);
	write_ppm_pixels(fd, canvas);
	close(fd);
}
