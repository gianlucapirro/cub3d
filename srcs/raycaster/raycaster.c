/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:33:37 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/06/27 13:08:15 by gianlucapir      ###   ########.fr       */
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

int	calc_dist(float *p1, float *p2)
{
	return (pow(fabsf(p1[0] - p2[0]), 2) + pow(fabsf(p1[1] - p2[1]), 2));
}

static int	get_next_vertical(float *fv, float direc[2], float nv[2])
{
	float	d;

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
	return (SUCCES);
}

static int	get_next_horizontal(float *fh, float direc[2], float nh[2])
{
	float	d;

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
	return (SUCCES);
}

/**
 * @brief Get the nxt intersect point, prev is the previous 
 * intersect horizontal or vertical horizon = 1, vertical = 0
 * 
 * @param fv 
 * @param fh 
 * @param prev 
 * @param d 
 * @return int 
 */
int	get_nxt_intersect(float *inter[2], int prev, float direc[2])
{
	float	nv[2];
	float	nh[2];
	float	*p_inter;

	get_next_horizontal(inter[1], direc, nh);
	get_next_vertical(inter[0], direc, nv);
	p_inter = inter[prev];
	if (inter[0] && (inter[1] == NULL || calc_dist(p_inter, nv) < calc_dist(p_inter, nh)))
	{
		inter[0][0] = nv[0];
		inter[0][1] = nv[1];
		return (0);
	}
	inter[1][0] = nh[0];
	inter[1][1] = nh[1];
	return (1);
}

int get_wall(t_config *config, float inter[2], int wall[3], t_ray *ray)
{
	float	ray_pos_on_wall;

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

int	cast(t_config *config, t_ray *ray)
{
	float	*inter[2]; //TODO: this is intersect v and h make this a struct
	int		prev;
	int		wall[3];

	inter[0] = pcalloc(sizeof(float) * 2);
	inter[1] = pcalloc(sizeof(float) * 2);
	if (first_intersect_v(config->pos, config->direction, inter[0]) == NOT_FOUND)
		inter[0] = NULL;
	if (first_intersect_h(config->pos, config->direction, inter[1]) == NOT_FOUND)
		inter[1] = NULL;
	prev = 1;
	if (!inter[1] || (inter[0] && calc_dist(inter[0], config->pos) < \
	calc_dist(inter[1], config->pos)))
		prev = 0;
	while (1) 
	{
		intersect_to_wall(config->direction, inter[prev], wall, prev);
		printf("Wall: %d %d %d\n", wall[0], wall[1], wall[2]);
		if (get_wall(config, inter[prev], wall, ray) == SUCCES)
			break ;
		prev = get_nxt_intersect(inter, prev, config->direction);
	}
	free(inter[0]);
	free(inter[1]);
	return (SUCCES); }
