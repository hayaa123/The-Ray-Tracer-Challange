#include "minirt.h"

int print_error_return(char *msg, int err)
{
    ft_putstr_fd(msg, 2);
    return(err);
}