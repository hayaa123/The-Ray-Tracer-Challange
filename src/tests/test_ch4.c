# include "minirt.h"

void test_ch4()
{
    t_matrix *m;
    t_matrix *n;
    t_tuple a;

    m = create_translation(5,-3,2);
    a = new_point(-3,4,5);
    is_equal_tuples(multi_matrix_tuple(*m, a), new_point(2, 1, 7));

    free_matrix(m);
    m = NULL;


    m = create_translation(5,-3,2);
    n =  invert_matrix(*m);
    a = new_point(-3,4,5);
    is_equal_tuples(multi_matrix_tuple(*n, a), new_point(-8, 7, 3));

    free_matrix(m);
    m = NULL;
    free_matrix(n);
    n = NULL;


    m = create_translation(5,-3, 2);
    a = new_vector(-3, 4, 5);
    is_equal_tuples(multi_matrix_tuple(*m, a), new_vector(-3, 4, 5));
    free_matrix(m);
    m = NULL;


    m = create_scaling(2, 3, 4);
    a = new_point(-4, 6, 8);
    is_equal_tuples(multi_matrix_tuple(*m, a), new_point(-8, 18, 32));
    free_matrix(m);
    m = NULL;


    m = create_scaling(2, 3, 4);
    a = new_vector(-4, 6, 8);
    is_equal_tuples(multi_matrix_tuple(*m, a), new_vector(-8, 18, 32));
    free_matrix(m);
    m = NULL;


    m = create_scaling(2, 3, 4);
    n = invert_matrix(*m);
    a = new_vector(-4, 6, 8);
    is_equal_tuples(multi_matrix_tuple(*n, a), new_vector(-2, 2, 2));
    free_matrix(m);
    m = NULL;
    free_matrix(n);
    n = NULL;


    m = rotation_x(M_PI / 4);
    n = rotation_x(M_PI / 2);
    a = new_point(0, 1, 0);
    is_equal_tuples(multi_matrix_tuple(*m, a), new_point(0, sqrt(2)/2, sqrt(2)/2));
    is_equal_tuples(multi_matrix_tuple(*n, a), new_point(0, 0, 1));
    free_matrix(m);
    m = NULL;
    free_matrix(n);
    n = NULL;


    m = rotation_x(M_PI / 4);
    n = invert_matrix(*m);
    a = new_point(0, 1, 0);
    is_equal_tuples(multi_matrix_tuple(*n, a), new_point(0, sqrt(2)/2, -1*sqrt(2)/2));
    free_matrix(m);
    m = NULL;
    free_matrix(n);
    n = NULL;


    m = rotation_y(M_PI / 4);
    n = rotation_y(M_PI / 2);
    a = new_point(0, 0, 1);
    is_equal_tuples(multi_matrix_tuple(*m, a), new_point(sqrt(2)/2, 0, sqrt(2)/2));
    is_equal_tuples(multi_matrix_tuple(*n, a), new_point(1, 0,0));
    free_matrix(m);
    m = NULL;
    free_matrix(n);
    n = NULL;
  

    m = rotation_z(M_PI / 4);
    n = rotation_z(M_PI / 2);
    a = new_point(0, 1, 0);
    is_equal_tuples(multi_matrix_tuple(*m, a), new_point(-sqrt(2)/2, sqrt(2)/2, 0));
    is_equal_tuples(multi_matrix_tuple(*n, a), new_point(-1, 0, 0));
    free_matrix(m);
    m = NULL;
    free_matrix(n);
    n = NULL;


    m = create_shear(1, 0, 0, 0, 0, 0);
    a = new_point(2, 3, 4);
    is_equal_tuples(multi_matrix_tuple(*m, a), new_point(5, 3, 4));
    free_matrix(m);
    m = NULL;

    
    m = create_shear(0, 1, 0, 0, 0, 0);
    a = new_point(2, 3, 4);
    is_equal_tuples(multi_matrix_tuple(*m, a), new_point(6, 3, 4));
    free_matrix(m);
    m = NULL;
 

    m = create_shear(0, 0, 1, 0, 0, 0);
    a = new_point(2, 3, 4);
    is_equal_tuples(multi_matrix_tuple(*m, a), new_point(2, 5, 4));
    free_matrix(m);
    m = NULL;
 

    m = create_shear(0, 0, 0, 1, 0, 0);
    a = new_point(2, 3, 4);
    is_equal_tuples(multi_matrix_tuple(*m, a), new_point(2, 7, 4));
    free_matrix(m);
    m = NULL;
 

    m = create_shear(0, 0, 0, 0, 1, 0);
    a = new_point(2, 3, 4);
    is_equal_tuples(multi_matrix_tuple(*m, a), new_point(2, 3, 6));
    free_matrix(m);
    m = NULL;
 

    m = create_shear(0, 0, 0, 0, 0, 1);
    a = new_point(2, 3, 4);
    is_equal_tuples(multi_matrix_tuple(*m, a), new_point(2, 3, 7));
    free_matrix(m);
    m = NULL;
 
}