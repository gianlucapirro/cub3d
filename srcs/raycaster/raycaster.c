/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:33:37 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/06/25 18:29:51 by gianlucapir      ###   ########.fr       */
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

static int	get_next_vertical(float *fv, float *d, float nv[2])
{
	if (fv == NULL)
		return (FAILED);
	// d[0] = 1 / config->direction[1] * config->direction[0];
	// d[1] = 1 / config->direction[0] * config->direction[1];
	printf("d: %f %f \n", d[0], d[1]);
	nv[0] = fv[0] - d[1];
	if (d[0] < 0)
		nv[0] = fv[0] + 1;
	else
		nv[0] = fv[0] - 1;
	return (SUCCES);
}

static int	get_next_horizontal(float *fh, float direc[2], float nh[2])
{
	float d;

	if (fh == NULL)
		return (FAILED);
	d = 1 / direc[1] * direc[0];
	nh[0] = fh[0] + d;
	if (direc[1] < 0)
		nh[1] = fh[1] - 1;
	else
		nh[1] = fh[1] + 1;
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
int	get_nxt_intersect(float *fv, float *fh, int prev, float direc[2])
{
	float	nv[2];
	float	nh[2];
	float	*p_inter;

	get_next_horizontal(fh, direc, nh);
	get_next_vertical(fv, direc, nv);
	prev = 1;
	if (prev == 0)
		p_inter = fv;
	else
		p_inter = fh;
	if (fv && (fh == NULL || calc_dist(p_inter, nv) < calc_dist(p_inter, nh)))
	{
		fv[0] = nv[0];
		fv[1] = nv[1];
		return (0);
	}
	fh[0] = nh[0];
	fh[1] = nh[1];
	return (1);
}

int	cast(t_config *config, t_data *img_data, float ray[2])
{
	float	*fv;
	float	*fh;
	float	d[2];
	int		i;
	int		prev;

	(void)ray;
	fv = pcalloc(sizeof(float) * 2);
	fh = pcalloc(sizeof(float) * 2);
	if (first_intersect_v(config->pos, config->direction, fv) == NOT_FOUND)
		fv = NULL;
	if (first_intersect_h(config->pos, config->direction, fh) == NOT_FOUND)
		fh = NULL;
	printf("direction: %f %f\n", config->direction[0], config->direction[1]);
	prev = 0;
	if (!fh || (fv && calc_dist(fv, config->pos) < calc_dist(fh, config->pos)))
		prev = 0;
	else
		prev = 1;
	i = 0;
	while (i < 1) 
	{
		prev = get_nxt_intersect(fv, fh, prev, d);
		if (prev == 0)
			draw_minimap_cross(config, img_data, fh);
		if (prev == 1)
			draw_minimap_cross(config, img_data, fh);
		i++;
	}
	free(fv);
	free(fh);
	return (0);
}