#include "minirt.h"


t_tuple new_tuple(float x, float y, float z, float w)
{
    return ((t_tuple){x,y,z,w});
}

t_tuple new_point(float x, float y, float z)
{
        return ((t_tuple){x,y,z,1});
}

t_tuple new_vector(float x, float y, float z)
{
        return ((t_tuple){x,y,z,0});
}

