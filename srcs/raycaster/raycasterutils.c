/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasterutils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 09:46:29 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/10/28 12:27:01 by gpirro        ########   odam.nl         */
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
