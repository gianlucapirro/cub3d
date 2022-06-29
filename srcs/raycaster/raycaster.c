/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycaster.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/24 19:33:37 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/06/28 19:37:53 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

float	calc_dist(float *p1, float *p2)
{
	return ((float)sqrt(pow((double)fabsf(p1[0] - p2[0]), (double)2) +\
			pow((double)fabsf(p1[1] - p2[1]), (double)2)));
}

int	first_intersect_h(float pos[2], float direc[2], float intersect[3])
{
	float	x;
	float	y;
	float	dx;
	float	dy;

	if (direc[1] == 0)
	{
		intersect[2] = INFINITY_INT;
		return (NOT_FOUND);
	}
	else if (direc[1] < 0)
		y = floor(pos[1]);
	else
		y = ceil(pos[1]);
	dy = pos[1] - y;
	dx = dy / direc[1] * direc[0];
	x = pos[0] - dx;
	intersect[0] = x;
	intersect[1] = y;
	intersect[2] = calc_dist(intersect, pos);
	return (SUCCES);
}

int	first_intersect_v(float pos[2], float direc[2], float intersect[3])
{
	float	x;
	float	y;
	float	dx;
	float	dy;

	if (direc[0] == 0)
	{
		intersect[2] = INFINITY_INT;
		return (NOT_FOUND);
	}
	else if (direc[0] < 0)
		x = floor(pos[0]);
	else
		x = ceil(pos[0]);
	dx = pos[0] - x;
	dy = dx / direc[0] * direc[1];
	y = pos[1] - dy;
	intersect[0] = x;
	intersect[1] = y;
	intersect[2] = calc_dist(intersect, pos);
	return (SUCCES);
}

static int	get_next_intersect(float vec[3], float direc[2], float pos[2], int v_or_h)
{
	float	d;
	float	new_vec[2];
	int		a;
	int		b;

	a = v_or_h;
	b = 1 - v_or_h;
	if (vec[2] == INFINITY_INT)
		return (FAILED);
	d = 1 / direc[a] * direc[b];
	if (direc[a] < 0)
	{
		new_vec[b] = vec[b] - d;
		new_vec[a] = vec[a] - 1;
	}
	else
	{
		new_vec[b] = vec[b] + d;
		new_vec[a] = vec[a] + 1;
	}
	vec[a] = new_vec[a];
	vec[b] = new_vec[b];
	vec[2] = calc_dist(vec, pos);
	return (SUCCES);
}

int get_wall(t_config *config, float inter[2], int wall[3], t_ray *ray)
{
	float	ray_pos_on_wall;

	if (wall[0] < 0 || wall[1] < 0 || wall[0] >= config->dimensions[0] || wall[1] >= config->dimensions[1])
		return (3);
	if (config->map[wall[1]][wall[0]] != WALL)
		return (FAILED);
	if (wall[2] == NORTH || wall[2] == SOUTH)
		ray_pos_on_wall = inter[0] - floor(inter[0]);
	else
		ray_pos_on_wall = inter[1] - floor(inter[1]);
	if (wall[2] == NORTH || wall[2] == EAST)
		ray_pos_on_wall = 1 - ray_pos_on_wall;
	ray->x = wall[0];
	ray->y = wall[1];
	ray->direction = wall[2];
	ray->pos_on_wall = ray_pos_on_wall; 
	ray->real_x = inter[0];
	ray->real_y = inter[1];
	return (SUCCES);
}

//axis 1 = horizontal, axis = 0 vertical
t_bool	intersect_to_wall(float direc[2], float inter[2], int wall[3], int axis)
{
	if (axis == 1 && direc[1] > 0)
	{
		wall[0] = (int)inter[0];
		wall[1] = (int)inter[1];
		wall[2] = SOUTH;
	}
	else if (axis == 1 && direc[1] < 0)
	{
		wall[0] = (int)inter[0];
		wall[1] = (int)inter[1] - 1;
		wall[2] = NORTH;
	}
	else if (axis == 0 && direc[0] > 0)
	{
		wall[0] = (int)inter[0];
		wall[1] = (int)inter[1];
		wall[2] = WEST;
	}
	else if (axis == 0 && direc[0] < 0)
	{			
		wall[0] = (int)inter[0] - 1;
		wall[1] = (int)inter[1];
		wall[2] = EAST;
	}
	return (TRUE);
}

int	get_closest_intersection(t_config *config, float *inter[2])
{
	if (!inter[0])
		return (1);
	else if (!inter[1])
		return (0);
	else if (calc_dist(inter[0], config->pos) < calc_dist(inter[1], config->pos))
		return (0);
	return (1);
}

int	cast(t_config *config, t_ray *ray, float direction[2])
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
		if (get_wall(config, inter[v_or_h], wall, ray) == SUCCES || get_wall(config, inter[v_or_h], wall, ray) == 3)
			break ;
		get_next_intersect(inter[v_or_h], direction, config->pos, v_or_h);
	}
	if (ray == NULL)
		return (FAILED);
	return (SUCCES);
}
