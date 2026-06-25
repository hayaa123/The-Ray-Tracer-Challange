#ifndef MINIRT_H
# define MINIRT_H


#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include "libft.h"
#include <stdio.h>
#include <math.h>
#include <fcntl.h>

typedef struct s_tuple
{
    float x;
    float y;
    float z;
    float w;
} t_tuple;

typedef struct s_color
{
    float red;
    float green;
    float blue;
} t_color;

typedef struct s_canvas
{
    int width;
    int height;
    t_color *pixels;
} t_canvas;

typedef struct s_projectile
{
    t_tuple  position;
    t_tuple  velocity;
} t_projectile;

typedef struct s_env
{
    t_tuple gravity;
    t_tuple wind;
} t_env;

typedef struct s_matrix
{
    float **data;
    int row;
    int col;
} t_matrix;

t_tuple new_tuple(float x, float y, float z, float w);
t_tuple new_point(float x, float y, float z);
t_tuple new_vector(float x, float y, float z);

// tuple_math1 methods
t_tuple add_tuples(t_tuple t1, t_tuple t2);
t_tuple sub_tuples(t_tuple t1, t_tuple t2);
t_tuple negate_tuple(t_tuple t);
t_tuple scale_tuple(t_tuple t, float scalar);
t_tuple divide_tuple(t_tuple t, float num);


// vector math
float vector_magnitude(t_tuple vector);
t_tuple normalize_vector(t_tuple vector);
float dot_product(t_tuple t1, t_tuple t2);


//tuple_utils.c
int is_equal_f(float a, float b);

// print utils
int print_error_return(char *msg, int err);

//testing 
void test_ch1();
void test_ch2();
void test_ch3();
void test_ch4();
void is_equal_floats(float a, float b);
void is_equal_tuples(t_tuple t1, t_tuple t2);
void is_equal_matrix_test(t_matrix *m1, t_matrix *m2);
void print_matrix(t_matrix *m);
void is_equal_color_test(t_color c1, t_color c2);


// canvas
t_color new_color(float red, float green, float blue);
t_color add_colors(t_color c1, t_color c2);
t_color sub_colors(t_color c1, t_color c2);
t_color scale_color(t_color t, float scalar);
t_color divide_color(t_color t, float num);
t_color mult_color(t_color c1, t_color c2);
t_canvas *new_canvas(int width, int height);
void free_canvas(t_canvas *canvas);
void write_pixel(t_canvas *canvas, int x, int y, t_color color);
t_color get_pixel(t_canvas *canvas, int x, int y);
void canvas_to_ppm(t_canvas *canvas, char *filename);


// matrix
t_matrix *new_matrix(float *values, int col, int row);
void free_matrix(t_matrix *m);
float **create_empty_data(int col, int row);

t_matrix *create_empty_matrix(int col, int row);
t_matrix *create_identity(int num);
t_matrix *create_transpose(t_matrix *m);

float calc_det(t_matrix m);
t_matrix *submatrix(t_matrix m, int row, int col);
float minor(t_matrix m, int row, int col);
float cofactor(t_matrix m, int row, int col);
t_matrix *divide_matrix_by(t_matrix m, float num);
t_matrix *invert_matrix(t_matrix m);
t_matrix *create_cofactor_matrix(t_matrix m);
int is_equal_matrix(t_matrix t1, t_matrix t2);
t_matrix *multi_matrix(t_matrix m1, t_matrix m2);
t_tuple multi_matrix_tuple(t_matrix m, t_tuple t);

// transformations
t_matrix *create_translation(float x, float y, float z);
t_matrix *create_scaling(float x, float y, float z);
t_matrix *rotation_x(float radians);
t_matrix *rotation_y(float radians);
t_matrix *rotation_z(float radians);
t_matrix *create_shear(float xy, float xz, float yx, float yz, float zx, float zy);



// ch1 ex
t_projectile new_projectile(t_tuple position, t_tuple velocity);
t_env new_env(t_tuple gravity, t_tuple wind);
t_projectile tick(t_env env, t_projectile projectile);


#endif