#include "minirt.h"

void is_equal_tuples(t_tuple *t1, t_tuple *t2)
{
    if(!is_equal_f(t1->x , t2->x))
        printf("tuples are not equal\n diff in x: %f, %f\n", t1->x, t2->x);
    else if(!is_equal_f(t1->y , t2->y))
        printf("tuples are not equal\n diff in y: %f, %f\n", t1->y, t2->y);
    else if(!is_equal_f(t1->z , t2->z))
        printf("tuples are not equal\n diff in z: %f, %f\n", t1->z, t2->z);
    else if(!is_equal_f(t1->w , t2->w))
        printf("tuples are not equal\n diff in w: %f, %f\n", t1->w, t2->w);
    else 
        printf ("Success\n");
    free(t1);
    free(t2);
}


void is_equal_floats(float a, float b)
{
    if(!is_equal_f(a , b))
        printf("floats are not equal\n diff: %f, %f\n", a, b);
    else 
        printf ("Success\n");
}

void test_ch1()
{
    // test point
    is_equal_tuples(new_point(1,2,3), new_tuple(1,2,3,1));
    // test vector 
    is_equal_tuples(new_vector(1,2,3), new_tuple(1,2,3,0));
    // test addition
    t_tuple *t1 = new_point(3,-2, 5);
    t_tuple *t2 = new_vector(-2, 3, 1);
    is_equal_tuples(add_tuples(*t1, *t2), new_tuple(1, 1, 6, 1));
    free(t1);
    free(t2);
    t1=NULL;
    t2 = NULL;

    // test supstraction
    //  2 points
    t1 = new_point(3, 2, 1);
    t2 = new_point(5, 6, 7);
    is_equal_tuples(sub_tuples(*t1, *t2), new_tuple(-2,-4,-6, 0));
    free(t1);
    free(t2);
    t1=NULL;
    t2 = NULL;

    //Subtracting a vector from a point
    t1 = new_point(3, 2, 1);
    t2 = new_vector(5, 6, 7);
    is_equal_tuples(sub_tuples(*t1, *t2), new_tuple(-2,-4,-6, 1));
    free(t1);
    free(t2);
    t1=NULL;
    t2 = NULL;

    // 2 vec
    t1 = new_vector(3, 2, 1);
    t2 = new_vector(5, 6, 7);
    is_equal_tuples(sub_tuples(*t1, *t2), new_tuple(-2,-4,-6, 0));
    free(t1);
    free(t2);
    t1=NULL;
    t2 = NULL;

    //Test Negating Tuples
    t1 = new_tuple(1,-2, 3,-4);
    is_equal_tuples(negate_tuple(*t1), new_tuple(-1, 2, -3, 4));
    free(t1);
    t1 = NULL;

    // Test Scalar multiplication 
    t1 = new_tuple(1,-2, 3,-4);
    is_equal_tuples(scale_tuple(*t1, 3.5), new_tuple(3.5,-7, 10.5, -14));
    free(t1);
    t1 = NULL;


    // Test Magnitude 
    t1 = new_vector(1, 0, 0);
    is_equal_floats(vector_magnitude(*t1), 1);
    free(t1);
    t1 = NULL;


    t1 = new_vector(0, 1, 0);
    is_equal_floats(vector_magnitude(*t1), 1);
    free(t1);
    t1 = NULL;

    t1 = new_vector(0, 0, 1);
    is_equal_floats(vector_magnitude(*t1), 1);
    free(t1);
    t1 = NULL;


    t1 = new_vector(1, 2, 3);
    is_equal_floats(vector_magnitude(*t1), sqrt(14));
    free(t1);
    t1 = NULL;

    t1 = new_vector(-1,-2,-3);
    is_equal_floats(vector_magnitude(*t1), sqrt(14));
    free(t1);
    t1 = NULL;

    //Testing normalization
    t1 = new_vector(1, 2, 3);
    t2 = normalize_vector(*t1);
    is_equal_tuples(normalize_vector(*t1), new_vector(0.26726, 0.53452, 0.80178));
    is_equal_floats(vector_magnitude(*t2), 1);
    free(t1);
    free(t2);
    t1 = NULL;
    t2 = NULL;

    // Testing dot product
    t1 = new_vector(1, 2, 3);
    t2 = new_vector(2, 3, 4);
    is_equal_floats(dot_product(*t1 ,*t2), 20);
    free(t1);
    free(t2);
    t1 = NULL;
    t2 = NULL;

}