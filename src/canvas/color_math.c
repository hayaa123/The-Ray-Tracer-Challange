#include "minirt.h"

t_color add_colors(t_color c1, t_color c2)
{
    return ((t_color){
        c1.red + c2.red,
        c1.green + c2.green,
        c1.blue + c2.blue
    });
}

t_color sub_colors(t_color c1, t_color c2)
{
    return ((t_color){
        c1.red - c2.red,
        c1.green - c2.green,
        c1.blue - c2.blue
    });
}

t_color scale_color(t_color c, float scalar)
{
    return ((t_color){
        c.red * scalar,
        c.green * scalar,
        c.blue * scalar
    });
}

t_color divide_color(t_color c, float num)
{
    return ((t_color){
        c.red / num,
        c.green / num,
        c.blue / num
    });
}

t_color mult_color(t_color c1, t_color c2)
{
    return ((t_color){
        c1.red * c2.red,
        c1.green * c2.green,
        c1.blue * c2.blue
    });
}