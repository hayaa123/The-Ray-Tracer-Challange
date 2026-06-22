#ifndef MINIRT_H
# define MINIRT_H

#include "libft.h"
#include <math.h>
#include <stdio.h>

typedef struct s_tuple
{
    float x;
    float y;
    float z;
    float w;
} t_tuple;

typedef struct s_matrix
{
    float **data;
    int row;
    int col;
} t_matrix;

t_tuple *new_tuple(float x, float y, float z, float w);
t_tuple *new_point(float x, float y, float z);
t_tuple *new_vector(float x, float y, float z);

// tuple_math1 methods
t_tuple *add_tuples(t_tuple t1, t_tuple t2);
t_tuple *sub_tuples(t_tuple t1, t_tuple t2);
t_tuple *negate_tuple(t_tuple t);
t_tuple *scale_tuple(t_tuple t, float scalar);
t_tuple *divaide_tuple(t_tuple t, float num);


// vector math
float vector_magnitude(t_tuple vector);
t_tuple *normalize_vector(t_tuple vector);
float dot_product(t_tuple t1, t_tuple t2);


//tuple_utils.c
int is_equal_f(float a, float b);

// print utils
int print_error_return(char *msg, int err);

//testing 
void test_ch1();
void is_equal_floats(float a, float b);
void is_equal_tuples(t_tuple *t1, t_tuple *t2);


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
t_matrix *divide_matrix_by(t_matrix m, int num);
t_matrix *invert_matrix(t_matrix m);
t_matrix *create_cofactor_matrix(t_matrix m);


int is_equal_matrix(t_matrix t1, t_matrix t2);
t_matrix *multi_matrix(t_matrix m1, t_matrix m2);
t_tuple *multi_matrix_tuple(t_matrix m, t_tuple t);
void print_matrix(t_matrix *m);




#endif