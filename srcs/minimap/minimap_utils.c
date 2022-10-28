/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 12:03:55 by gpirro        #+#    #+#                 */
/*   Updated: 2022/10/28 12:22:12 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	set_data_wall_ns(t_point *s, t_point *e, int wall[3])
{
	if (wall[2] == NORTH)
	{
		s->x = wall[0];
		s->y = wall[1] + 1;
		e->x = wall[0] + 1;
		e->y = wall[1] + 1;
	}
	if (wall[2] == SOUTH)
	{
		s->x = wall[0];
		s->y = wall[1];
		e->x = wall[0] + 1;
		e->y = wall[1];
	}
	return (SUCCES);
}

int	set_data_wall_ew(t_point *s, t_point *e, int wall[3])
{
	if (wall[2] == EAST)
	{
		s->x = wall[0] + 1;
		s->y = wall[1];
		e->x = wall[0] + 1;
		e->y = wall[1] + 1;
	}
	if (wall[2] == WEST)
	{
		s->x = wall[0];
		s->y = wall[1];
		e->x = wall[0];
		e->y = wall[1] + 1;
	}
	return (SUCCES);
}

/**
 * @brief draws a rectangle, give pos (x/y), and the dimensions 
 * of the rectangle (width/height)
 * 
 * @param x 
 * @param y 
 * @param dimensions 
 * @param img 
 * @return int 
 */
int	draw_rectangle(int pos[2], int dimensions[2], mlx_image_t *img, int color)
{
	const int	x = pos[0];
	const int	y = pos[1];
	int			w;
	int			h;

	w = -1;
	while (++w < dimensions[0])
	{
		h = -1;
		while (++h < dimensions[1])
			mlx_put_pixel(img, x + w, y - h, color);
	}
	return (SUCCES);
}
