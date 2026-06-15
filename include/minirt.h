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

#endif