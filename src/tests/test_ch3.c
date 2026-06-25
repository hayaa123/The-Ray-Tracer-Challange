#include "minirt.h"

void test_ch3()
{
    t_matrix *m = new_matrix((float[]){
        1 , 2 , 3 , 4,
        5.5, 6.5, 7.5, 8.5,
        9, 10, 11, 12,
        13.5, 14.5, 15.5, 16.5
    }, 4, 4);
    is_equal_floats(m->data[0][0], 1);
    is_equal_floats(m->data[0][3], 4);
    is_equal_floats(m->data[1][0], 5.5);
    is_equal_floats(m->data[1][2], 7.5);
    is_equal_floats(m->data[2][2], 11);
    is_equal_floats(m->data[3][0], 13.5);
    is_equal_floats(m->data[3][2], 15.5);
    free_matrix(m);
    m = NULL;


    m = new_matrix((float[]){
    -3, 5,
    1, -2
    }, 2, 2);
    is_equal_floats(m->data[0][0], -3);
    is_equal_floats(m->data[0][1], 5);
    is_equal_floats(m->data[1][0], 1);
    is_equal_floats(m->data[1][1], -2);
    free_matrix(m);
    m = NULL;

    m = new_matrix((float[]){
    -3, 5,
    1, -2
    }, 2, 2);

    t_matrix *n = new_matrix((float[]){
    -3, 5,
    1, -2
    }, 2, 2);
    is_equal_floats(is_equal_matrix(*n , *m), 1);
    free_matrix(m);
    m = NULL;
    free_matrix(n);
    n = NULL;


    m = new_matrix((float[]){
    1 , 2 , 3 , 4 ,
    5 , 6 , 7 , 8 ,
    9 , 8 , 7 , 6 ,
    5 , 4 , 3 , 2 
    }, 4, 4);

     n = new_matrix((float[]){
    2 , 3 , 4 , 5  ,
    6 , 7 , 8 , 9 ,
    8 , 7 , 6 , 5 ,
    4 , 3 , 2 , 1 
    }, 4, 4);

    is_equal_floats(is_equal_matrix(*n , *m), 0);
    free_matrix(m);
    m = NULL;
    free_matrix(n);
    n = NULL;


    m = new_matrix((float[]){
    1 , 2 , 3 , 4 ,
    5 , 6 , 7 , 8 ,
    9 , 8 , 7 , 6 ,
    5 , 4 , 3 , 2 
    }, 4, 4);

    n = new_matrix((float[]){
    -2 , 1 , 2 , 3 ,
    3 , 2 , 1 ,-1 ,
    4 , 3 , 6 , 5 ,
    1 , 2 , 7 , 8 
    }, 4, 4);

    is_equal_matrix_test(multi_matrix(*m, *n), new_matrix((float[]){
    20,22 ,50 ,48 
    ,44,54 ,114 ,108 
    ,40,58 ,110 ,102 
    ,16,26 ,46 ,42 
    }, 4, 4));
    free_matrix(m);
    free_matrix(n);
    m = NULL;
    n = NULL;
    
    m = new_matrix((float[])
    {
        1 , 2 , 3 , 4 ,
        2 , 4 , 4 , 2 ,
        8 , 6 , 4 , 1 ,
        0 , 0 , 0 , 1 
    }, 4,4);

    t_tuple a = new_tuple(1,2,3,1);
    is_equal_tuples(new_tuple(18, 24, 33, 1), multi_matrix_tuple(*m, a));
    free_matrix(m);
    m = NULL;

    m = new_matrix((float[])
    {
        0 , 9 , 3 , 0 ,
        9 , 8 , 0 , 8 ,
        1 , 8 , 5 , 3 ,
        0 , 0 , 5 , 8
    }, 4,4);

    is_equal_matrix_test(create_transpose(m), new_matrix((float[]){
        0 , 9 , 1 , 0,
        9 , 8 , 8 , 0, 
        3 , 0 , 5 , 5, 
        0 , 8 , 3 , 8 
    }, 4, 4));

    free_matrix(m);
    m = NULL;
    
    m = create_identity(4);
    is_equal_matrix_test(create_transpose(m), m);
    
    m = new_matrix((float[]){
        1 , 5 ,
        -3 , 2 
    },2,2);
    is_equal_f(calc_det(*m), 17);
    free_matrix(m);
    m = NULL;


    m = new_matrix((float[]){
    1 , 5 , 0 ,
    -3 , 2 , 7 ,
    0 , 6 ,-3 
    },3,3);
    is_equal_matrix_test(submatrix(*m, 0, 2), new_matrix((float[]){
        -3 , 2 ,
        -0 , 6 
    },2,2));
    free_matrix(m);
    m = NULL;


    m = new_matrix((float[]){
    -6 , 1 , 1 , 6 ,
    -8 , 5 , 8 , 6 ,
    -1 , 0 , 8 , 2 ,
    -7 , 1 ,-1 , 1 
    },4,4);
    is_equal_matrix_test(submatrix(*m, 2, 1), new_matrix((float[]){
    -6 , 1 , 6 ,
    -8 , 8 , 6 ,
    -7 ,-1 , 1
    },3,3));
    free_matrix(m);
    m = NULL;

    m = new_matrix((float[]){
    3 , 5 , 0 ,
    2 ,-1 ,-7 ,
    6 ,-1 , 5 
    },3,3);

    n = submatrix(*m, 1,0);
    is_equal_floats(calc_det(*n),25);
    is_equal_floats(minor(*m,1,0),25);

    free_matrix(m);
    m = NULL;
    free_matrix(n);
    n = NULL;

    m = new_matrix((float[]){
        3, 5, 0,
        2, -1, -7,
        6, -1, 5
    },3,3);
    is_equal_floats(minor(*m, 0, 0), -12);
    is_equal_floats(cofactor(*m, 0, 0), -12);
    is_equal_floats(minor(*m, 1, 0), 25);
    is_equal_floats(cofactor(*m, 1, 0), -25);
    free_matrix(m);
    m = NULL;


    m = new_matrix((float[]){
    1 , 2 , 6 ,
    -5 , 8 ,-4 ,
    2 , 6 , 4 
    },3,3);
    is_equal_floats(cofactor(*m, 0, 0), 56);
    is_equal_floats(cofactor(*m, 0, 1), 12);
    is_equal_floats(cofactor(*m, 0, 2), -46);
    is_equal_floats(calc_det(*m), -196);
    free_matrix(m);
    m = NULL;

    m = new_matrix((float[]){
    -2 ,-8 , 3 , 5 ,
    -3 , 1 , 7 , 3 ,
    1 , 2 ,-9 , 6 ,
    -6 , 7 , 7 ,-9 
    }, 4, 4);  
    is_equal_floats(cofactor(*m, 0, 0), 690);
    is_equal_floats(cofactor(*m, 0, 1), 447);
    is_equal_floats(cofactor(*m, 0, 2), 210);
    is_equal_floats(cofactor(*m, 0, 3), 51);
    is_equal_floats(calc_det(*m), -4071);
    free_matrix(m);
    m = NULL;

    m = new_matrix((float[]){
    6 , 4 , 4 , 4 ,
    5 , 5 , 7 , 6 ,
    4 ,-9 , 3 ,-7 ,
    9 , 1 , 7 ,-6 
    }, 4, 4);   
    is_equal_floats(calc_det(*m), -2120);
    free_matrix(m);
    m = NULL;

    m = new_matrix((float[]){
    -4 , 2 ,-2 ,-3 ,
    9 , 6 , 2 , 6 ,
    0 ,-5 , 1 ,-5 ,
    0 , 0 , 0 , 0 
    }, 4, 4);
    is_equal_floats(calc_det(*m), 0);
    free_matrix(m);
    m = NULL;


    m = new_matrix((float[]){
    8 ,-5 , 9 , 2 ,
    7 , 5 , 6 , 1 ,
    -6 , 0 , 9 , 6 ,
    -3 , 0 ,-9 ,-4 
    }, 4, 4);
    is_equal_matrix_test(invert_matrix(*m), new_matrix((float[]){
    -0.15385 ,-0.15385 ,-0.28205 ,-0.53846 ,
    -0.07692 , 0.12308 , 0.02564 , 0.03077 ,
    0.35897 , 0.35897 , 0.43590 , 0.92308 ,
    -0.69231 ,-0.69231 ,-0.76923 ,-1.92308}, 4, 4));
    free_matrix(m);
    m = NULL;


    
    m = new_matrix((float[]){
    9 , 3 , 0 , 9 ,
    -5 ,-2 ,-6 ,-3 ,
    -4 , 9 , 6 , 4 ,
    -7 , 6 , 6 , 2
    }, 4, 4);
    is_equal_matrix_test(invert_matrix(*m), new_matrix((float[]){
    -0.04074 ,-0.07778 , 0.14444 ,-0.22222 ,
    -0.07778 , 0.03333 , 0.36667 ,-0.33333 ,
    -0.02901 ,-0.14630 ,-0.10926 , 0.12963 ,
     0.17778 , 0.06667 ,-0.26667 , 0.33333
    }, 4, 4));
    free_matrix(m);
    m = NULL;

    m = new_matrix((float[]){
    3 ,-9 , 7 , 3 ,
    3 ,-8 , 2 ,-9 ,
    -4 , 4 , 4 , 1 ,
    -6 , 5 ,-1 , 1 
    }, 4, 4);

    n = new_matrix((float[]){
    8 , 2 , 2 , 2 ,
    3 ,-1 , 7 , 0 ,
    7 , 0 , 5 , 4 ,
    6 ,-2 , 0 , 5 
    }, 4, 4);

    t_matrix *c;
    c = multi_matrix(*m , *n);

    t_matrix *invn = invert_matrix(*n);    
    is_equal_matrix_test(multi_matrix(*c , *invn), m);

    free_matrix(n);
    n = NULL;
    free_matrix(c);
    c = NULL;
    free_matrix(invn);
    invn = NULL;
}