#include "minirt.h"

t_matrix *create_translation(float x, float y, float z)
{
    t_matrix *result;

    result = create_identity(4);
    if(!result)
        return (NULL);
    result->data[0][3] = x;
    result->data[1][3] = y;
    result->data[2][3] = z;

    return (result);
}