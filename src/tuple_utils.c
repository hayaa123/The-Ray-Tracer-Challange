#include "minirt.h"

const float e = 0.00001;

int is_equal_f(float a, float b)
{
    if(fabs(a - b) < e)
        return(1);
    else 
        return(0);    
}