/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasterutils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 09:46:29 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/10/27 18:20:33 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// fix fish eye, make all rays to wall same size.
float	fix_fish_eye(float pos[2], float inter[2], float direc[2])
{
	float	u[2];
	float	v[2];
	float	c;
	float	d;

	u[0] = inter[0] - pos[0];
	u[1] = inter[1] - pos[1];
	v[0] = direc[0];
	v[1] = direc[1];
	c = sqrt((u[0] * u[0]) + (u[1] * u[1]));
	d = sqrt((v[0] * v[0]) + (v[1] * v[1]));
	u[0] = u[0] / c;
	u[1] = u[1] / c;
	v[0] = v[0] / d;
	v[1] = v[1] / d;
	d = u[0] * v[0] + u[1] * v[1];
	return (d);
}

//inter has intersec x and y in each array is x, y, distance
int	cast(t_config *config, t_ray *ray, float direction[2], float angle)
{
	float	inter[2][3];
	int		v_or_h;
	int		wall[3];

	first_intersect_v(config->pos, direction, inter[0]);
	first_intersect_h(config->pos, direction, inter[1]);
	while (1)
	{
		v_or_h = inter[0][2] > inter[1][2];
		intersect_to_wall(direction, inter[v_or_h], wall, v_or_h);
		if (get_wall(config, inter[v_or_h], wall, ray) == SUCCES || \
		get_wall(config, inter[v_or_h], wall, ray) == 3)
		{
			ray->distance = inter[v_or_h][2] * \
			(float)cos((double)deg_to_rad(angle));
			break ;
		}
		get_next_intersect(inter[v_or_h], direction, config->pos, v_or_h);
	}
	if (ray == NULL)
		return (FAILED);
	return (SUCCES);
}
