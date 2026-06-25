#include "minirt.h"

void is_equal_tuples(t_tuple t1, t_tuple t2)
{
    if(!is_equal_f(t1.x , t2.x))
        printf("tuples are not equal\n diff in x: %f, %f\n", t1.x, t2.x);
    else if(!is_equal_f(t1.y , t2.y))
        printf("tuples are not equal\n diff in y: %f, %f\n", t1.y, t2.y);
    else if(!is_equal_f(t1.z , t2.z))
        printf("tuples are not equal\n diff in z: %f, %f\n", t1.z, t2.z);
    else if(!is_equal_f(t1.w , t2.w))
        printf("tuples are not equal\n diff in w: %f, %f\n", t1.w, t2.w);
    else 
        printf ("Success\n");

}

void is_equal_floats(float a, float b)
{
    if(!is_equal_f(a , b))
        printf("floats are not equal\n diff: %f, %f\n", a, b);
    else 
        printf ("Success\n");
}

void is_equal_matrix_test(t_matrix *m1, t_matrix *m2)
{
    if(!is_equal_matrix(*m1, *m2))
    {
        printf("the two matrix are not equal\n");
    }
    else{
        printf("Success\n");
    }
    free_matrix(m1);
    free_matrix(m2);
}

void is_equal_color_test(t_color c1, t_color c2)
{
    if(!is_equal_f(c1.red , c2.red))
        printf("colors are not equal\n diff in red: %f, %f\n", c1.red, c2.red);
    else if(!is_equal_f(c1.green , c2.green))
        printf("colors are not equal\n diff in green: %f, %f\n", c1.green, c2.green);
    else if(!is_equal_f(c1.blue , c2.blue))
        printf("colors are not equal\n diff in blue: %f, %f\n", c1.blue, c2.blue);
    else 
        printf ("Success\n");
}