#include "minirt.h"

t_tuple *add_tuples(t_tuple t1, t_tuple t2)
{
    t_tuple* result;

    if(t1.w == 1 && t2.w == 1)
    {
        print_error_return("Cannot add two points together", 1);
        return (NULL);
    }
    result = ft_calloc(1, sizeof(t_tuple));
    result->x = t1.x + t2.x;
    result->y = t1.y + t2.y;
    result->z = t1.z + t2.z;
    result->w = t1.w + t2.w;
    return (result);
}

t_tuple *sub_tuples(t_tuple t1, t_tuple t2)
{
    t_tuple* result;

    if(t1.w - t2.w < 0)
    {
        print_error_return("Negative wight\n", 1);
        return (NULL);
    }
    result = ft_calloc(1, sizeof(t_tuple));
    result->x = t1.x - t2.x;
    result->y = t1.y - t2.y;
    result->z = t1.z - t2.z;
    result->w = t1.w - t2.w;
    return (result);
}

t_tuple *negate_tuple(t_tuple t)
{
    t_tuple* result;
    result = ft_calloc(1, sizeof(t_tuple));
    result->x = 0 - t.x;
    result->y = 0 - t.y;
    result->z = 0 - t.z;
    result->w = 0 - t.w;
    return (result);
}

t_tuple *scale_tuple(t_tuple t, float scalar)
{
    t_tuple* result;

    result = ft_calloc(1, sizeof(t_tuple));
    result->x = t.x * scalar;
    result->y = t.y * scalar;
    result->z = t.z * scalar;
    result->w = t.w * scalar;
    return (result);
}

t_tuple *divaide_tuple(t_tuple t, float num)
{
    t_tuple* result;

    result = ft_calloc(1, sizeof(t_tuple));
    result->x = t.x / num;
    result->y = t.y / num;
    result->z = t.z / num;
    result->w = t.w / num;
    return (result);
}
