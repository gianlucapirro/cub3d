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

int	first_intersect_h(float pos[2], float direc[2], float intersect[2])
{
	float	x;
	float	y;
	float	dx;
	float	dy;

	if (direc[1] == 0)
		return (NOT_FOUND);
	else if (direc[1] < 0)
		y = floor(pos[1]);
	else
		y = ceil(pos[1]);
	dy = pos[1] - y;
	dx = dy / direc[1] * direc[0];
	x = pos[0] - dx;
	intersect[0] = x;
	intersect[1] = y;
	return (SUCCES);
}

int	first_intersect_v(float pos[2], float direc[2], float intersect[2])
{
	float	x;
	float	y;
	float	dx;
	float	dy;

	if (direc[0] == 0)
		return (NOT_FOUND);
	else if (direc[0] < 0)
		x = floor(pos[0]);
	else
		x = ceil(pos[0]);
	dx = pos[0] - x;
	dy = dx / direc[0] * direc[1];
	y = pos[1] - dy;
	intersect[0] = x;
	intersect[1] = y;
	return (SUCCES);
}

float	calc_dist(float *p1, float *p2)
{
	return (pow(fabsf(p1[0] - p2[0]), 2) + pow(fabsf(p1[1] - p2[1]), 2));
}

static int	get_next_vertical(float *fv, float direc[2])
{
	float	d;
	float	nv[2];

	if (fv == NULL)
		return (FAILED);
	d = 1 / direc[0] * direc[1];
	if (direc[0] < 0)
	{
		nv[1] = fv[1] - d;
		nv[0] = fv[0] - 1;
	}
	else
	{
		nv[1] = fv[1] + d;
		nv[0] = fv[0] + 1;
	}
	fv[0] = nv[0];
	fv[1] = nv[1];
	return (SUCCES);
}

static int	get_next_horizontal(float *fh, float direc[2])
{
	float	d;
	float	nh[2];

	if (fh == NULL)
		return (FAILED);
	d = 1 / direc[1] * direc[0];
	if (direc[1] < 0)
	{
		nh[0] = fh[0] - d;
		nh[1] = fh[1] - 1;
	}
	else
	{
		nh[0] = fh[0] + d;
		nh[1] = fh[1] + 1;
	}
	fh[0] = nh[0];
	fh[1] = nh[1];
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

int	cast(t_config *config, t_ray *ray, t_data *img_data)
{
	float	*inter[2];
	int		prev;
	int		wall[3];

	inter[0] = pcalloc(sizeof(float) * 2);
	inter[1] = pcalloc(sizeof(float) * 2);
	if (first_intersect_v(config->pos, config->direction, inter[0]) == NOT_FOUND)
		inter[0] = NULL;
	if (first_intersect_h(config->pos, config->direction, inter[1]) == NOT_FOUND)
		inter[1] = NULL;
	while (1) 
	{
		prev = get_closest_intersection(config, inter);
		draw_minimap_cross(config, img_data, inter[prev]);
		intersect_to_wall(config->direction, inter[prev], wall, prev);
		if (get_wall(config, inter[prev], wall, ray) == SUCCES || get_wall(config, inter[prev], wall, ray) == 3)
			break ;
		if (prev == 0)
			get_next_vertical(inter[0], config->direction);
		else
			get_next_horizontal(inter[1], config->direction);
	}
	if (ray == NULL)
		return (FAILED);
	free(inter[0]);
	free(inter[1]);
	return (SUCCES);
}
