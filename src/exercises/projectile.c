#include "minirt.h"

t_projectile new_projectile(t_tuple position, t_tuple velocity)
{
    return ((t_projectile){position, velocity});
}

t_env new_env(t_tuple gravity, t_tuple wind)
{
    return ((t_env){gravity, wind});
}

t_projectile tick(t_env env, t_projectile projectile)
{
    return(
        (t_projectile){
            add_tuples(projectile.position, projectile.velocity),
            add_tuples(projectile.velocity, add_tuples(env.gravity, env.wind))
        }
    );
}