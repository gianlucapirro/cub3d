/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:30:10 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/10/14 10:24:20 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	free_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	return (SUCCES);
}

float	calc_dist(float *p1, float *p2)
{
	return ((float)sqrt(pow((double)fabsf(p1[0] - p2[0]), (double)2) + \
			pow((double)fabsf(p1[1] - p2[1]), (double)2)));
}

int	get_closest_intersection(t_config *config, float *inter[2])
{
	if (!inter[0])
		return (1);
	else if (!inter[1])
		return (0);
	else if (calc_dist(inter[0], config->pos) \
	< calc_dist(inter[1], config->pos))
		return (0);
	return (1);
}

/*
 Takes a double x and returns the absolute value of the number
 */
double	dabs(double x)
{
	if (x < 0)
		return (x * -1);
	else
		return (x);
}

int	draw_minimap_cross(t_config *conf, t_data *img_data, float pos[2])
{
	int	mpos[2];

	mpos[0] = (int)(pos[0] * conf->block_size[0]);
	mpos[1] = (int)(pos[1] * conf->block_size[1]);
	draw_cross(img_data, mpos, 5);
	return (SUCCES);
}
