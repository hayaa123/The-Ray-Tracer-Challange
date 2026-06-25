#include "minirt.h"

void test_ch1()
{
    // test point
    is_equal_tuples(new_point(1,2,3), new_tuple(1,2,3,1));
    // test vector 
    is_equal_tuples(new_vector(1,2,3), new_tuple(1,2,3,0));
    // test addition
    t_tuple t1 = new_point(3,-2, 5);
    t_tuple t2 = new_vector(-2, 3, 1);
    is_equal_tuples(add_tuples(t1, t2), new_tuple(1, 1, 6, 1));

    // test supstraction
    //  2 points
    t1 = new_point(3, 2, 1);
    t2 = new_point(5, 6, 7);
    is_equal_tuples(sub_tuples(t1, t2), new_tuple(-2,-4,-6, 0));

    //Subtracting a vector from a point
    t1 = new_point(3, 2, 1);
    t2 = new_vector(5, 6, 7);
    is_equal_tuples(sub_tuples(t1, t2), new_tuple(-2,-4,-6, 1));

    // 2 vec
    t1 = new_vector(3, 2, 1);
    t2 = new_vector(5, 6, 7);
    is_equal_tuples(sub_tuples(t1, t2), new_tuple(-2,-4,-6, 0));

    //Test Negating Tuples
    t1 = new_tuple(1,-2, 3,-4);
    is_equal_tuples(negate_tuple(t1), new_tuple(-1, 2, -3, 4));

    // Test Scalar multiplication 
    t1 = new_tuple(1,-2, 3,-4);
    is_equal_tuples(scale_tuple(t1, 3.5), new_tuple(3.5,-7, 10.5, -14));


    // Test Magnitude 
    t1 = new_vector(1, 0, 0);
    is_equal_floats(vector_magnitude(t1), 1);


    t1 = new_vector(0, 1, 0);
    is_equal_floats(vector_magnitude(t1), 1);

    t1 = new_vector(0, 0, 1);
    is_equal_floats(vector_magnitude(t1), 1);


    t1 = new_vector(1, 2, 3);
    is_equal_floats(vector_magnitude(t1), sqrt(14));

    t1 = new_vector(-1,-2,-3);
    is_equal_floats(vector_magnitude(t1), sqrt(14));

    //Testing normalization
    t1 = new_vector(1, 2, 3);
    t2 = normalize_vector(t1);
    is_equal_tuples(normalize_vector(t1), new_vector(0.26726, 0.53452, 0.80178));
    is_equal_floats(vector_magnitude(t2), 1);


    // Testing dot product
    t1 = new_vector(1, 2, 3);
    t2 = new_vector(2, 3, 4);
    is_equal_floats(dot_product(t1 ,t2), 20);

    printf("ch1-ex solution test\n");
    t_projectile p;
    t_env  e;

    p = new_projectile(new_point(0,1,0), normalize_vector(new_vector(1,1,0)));
    e = new_env(new_vector(0,-0.1, 0), new_vector(-0.01, 0, 0));

    while(p.position.y > 0)
    {
        printf("position: (%f,%f,%f)\n", p.position.x, p.position.y, p.position.z);
        p = tick(e, p);
    }
}