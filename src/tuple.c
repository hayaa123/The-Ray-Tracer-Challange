#include "minirt.h"


t_tuple *new_tuple(float x, float y, float z, float w)
{
    t_tuple *point;

    point = ft_calloc(1, sizeof(t_tuple));
    if(!point)
        return (NULL);
    point->x = x;
    point->y = y;
    point->z = z;
    point->w = w;
    return (point);
}

t_tuple *new_point(float x, float y, float z)
{
    return (new_tuple(x, y, z, 1));
}

t_tuple *new_vector(float x, float y, float z)
{
    return (new_tuple(x, y, z, 0));
}

