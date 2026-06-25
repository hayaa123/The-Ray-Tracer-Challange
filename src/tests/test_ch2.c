#include "minirt.h"

void test_ch2()
{
    t_color c1;
    t_color c2;
    t_color c3;
    t_canvas *canvas;

    printf(" Colors are (red, green, blue) tuples\n");
    c1 = new_color(-0.5, 0.4, 1.7);
    is_equal_floats(c1.red, -0.5);
    is_equal_floats(c1.green, 0.4);
    is_equal_floats(c1.blue, 1.7);


    printf("Adding colors:\n");
    c1 = new_color(0.9, 0.6, 0.75);
    c2 = new_color(0.7, 0.1, 0.25);
    is_equal_color_test(add_colors(c1, c2), new_color(1.6, 0.7, 1.0));
    
    printf("Subtracting colors:\n");
    c1 = new_color(0.9, 0.6, 0.75);
    c2 = new_color(0.7, 0.1, 0.25);
    is_equal_color_test(sub_colors(c1, c2), new_color(0.2, 0.5, 0.5));


    printf("Multiplying a color by a scalar:\n");
    c1 = new_color(0.2, 0.3, 0.4);;
    is_equal_color_test(scale_color(c1, 2), new_color(0.4, 0.6, 0.8));


    printf("Multiplying colors:\n");
    c1 = new_color(1, 0.2, 0.4);
    c2 = new_color(0.9, 1, 0.1);
    is_equal_color_test(mult_color(c1, c2), new_color(0.9, 0.2, 0.04));

    printf("Creating a canvas:\n");
    canvas = new_canvas(10,20);
    is_equal_floats(canvas->width, 10);
    is_equal_floats(canvas->height, 20);
    for(int i=0; i < canvas->width * canvas->height; i++)
        is_equal_color_test(canvas->pixels[i], new_color(0,0,0));
    free_canvas(canvas);
    canvas = NULL;

    printf("Writing pixels to a canvas\n");
    canvas = new_canvas(10,20);
    c1 = new_color(1,0,0);
    write_pixel(canvas, 2, 3, c1);
    is_equal_color_test(get_pixel(canvas, 2, 3), c1);
    free_canvas(canvas);
    canvas = NULL;

    printf("test ppm files is located inside imgs/ch2/ directory :D\n");
    printf("Constructing the PPM header - output called test1\n");
    canvas = new_canvas(5, 3);
    canvas_to_ppm(canvas, "imgs/ch2/test1.ppm");
    free_canvas(canvas);
    canvas = NULL;

    printf("Constructing the PPM pixel data - output called test2\n");
    canvas = new_canvas(5, 3);
    c1 = new_color(1.5, 0, 0);
    c2 = new_color(0, 0.5, 0);
    c3 = new_color(-0.5, 0, 1);
    write_pixel(canvas, 0, 0, c1);
    write_pixel(canvas, 2, 1, c2);
    write_pixel(canvas, 4, 2, c3);
    canvas_to_ppm(canvas, "imgs/ch2/test2.ppm");
    free_canvas(canvas);
    canvas = NULL;

    printf("Splitting long lines in PPM files - output called test3\n");
    canvas = new_canvas(10, 2);
    c1 = new_color(1, 0.8, 0.6);
    for(int i=0; i < canvas->height; i++)
        for(int j=0; j < canvas->width; j++)
            write_pixel(canvas, j, i, c1);
    canvas_to_ppm(canvas, "imgs/ch2/test3.ppm");
    free_canvas(canvas);
    canvas = NULL;

    printf("finish exercise\n");

    t_tuple start = new_point(0, 1, 0);
    t_tuple velocity = scale_tuple(normalize_vector(new_vector(1, 1.8, 0)), 11.25);
    t_projectile p = new_projectile(start, velocity);
    t_tuple gravity = new_vector(0,-0.1, 0);
    t_tuple wind = new_vector(-0.01, 0, 0);
    t_env e = new_env(gravity, wind);
    canvas = new_canvas(900, 550);
    while(p.position.y > 0)
    {
        printf("position: (%f,%f,%f)\n", p.position.x, p.position.y, p.position.z);
        write_pixel(canvas, p.position.x, canvas->height - p.position.y, new_color(1,0,0));
        p = tick(e, p);
    }
    canvas_to_ppm(canvas, "imgs/ch2/exercise-ch2.ppm");
    free_canvas(canvas);
    canvas = NULL;
}
