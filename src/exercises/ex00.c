#include "minirt.h"

int main()
{
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