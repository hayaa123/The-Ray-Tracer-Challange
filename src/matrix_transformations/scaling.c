#include "minirt.h"

t_matrix *create_scaling(float x, float y, float z)
{
    t_matrix *result;

    result = create_identity(4);
    if(!result)
        return (NULL);
    result->data[0][0] = x;
    result->data[1][1] = y;
    result->data[2][2] = z;

    return (result);
}