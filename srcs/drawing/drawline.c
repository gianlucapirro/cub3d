/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawline.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/24 17:16:24 by gpirro        #+#    #+#                 */
/*   Updated: 2022/10/27 18:13:45 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/*
 If  the value of a2 is smaller than the value of a1 it will swap 
 the value of a2 with a1 and the value of b2 with b1
 */
static void	swap_smallest(int *a1, double *b1, int *a2, double *b2)
{
	double	tmp;

	if (*a2 < *a1)
	{
		tmp = *a2;
		*a2 = *a1;
		*a1 = tmp;
		tmp = *b2;
		*b2 = *b1;
		*b1 = tmp;
	}
}

/*
 This function is used when the slope is smaller than 1 to
 draw a steap line
 */
static void	put_line_steap(mlx_image_t *data, t_point *p1, t_point *p2, int color)
{
	double	slope;
	int		x1;
	int		x2;
	double	y1;
	double	y2;

	x1 = (int)p1->x;
	y1 = p1->y;
	x2 = (int)p2->x;
	y2 = p2->y;
	swap_smallest(&x1, &y1, &x2, &y2);
	slope = (y1 - y2) / (x1 - x2);
	while (x1 != x2)
	{
		y1 += slope;
		x1++;
		mlx_put_pixel(data, x1, (int)y1, color);
	}
}

/*
 This function is used when the slope is bigger than 1
 to draw a gentle line
 */
static void	put_line_gentle(mlx_image_t *data, t_point *p1, t_point *p2, int color)
{
	double	slope;
	double	x1;
	double	x2;
	int		y1;
	int		y2;

	x1 = p1->x;
	y1 = (int)p1->y;
	x2 = p2->x;
	y2 = (int)p2->y;
	swap_smallest(&y1, &x1, &y2, &x2);
	slope = (x1 - x2) / (y1 - y2);
	while (y1 != y2)
	{
		x1 += slope;
		y1++;
		mlx_put_pixel(data, (int)x1, y1, color);
	}
}

/*
 Uses the putpixel function to draw a line. If the slope is
 bigger than 1 it will use the function put_line_gentle else it will use
 put_line_steap to draw the line
 */
void	draw_line(mlx_image_t *data, t_point *p1, t_point *p2, int color)
{
	double	slope;

	if ((int)p1->x == (int)p2->x && (int)p1->y == (int)p2->y)
		return ;
	else if ((int)p1->x == (int)p2->x)
		slope = 1;
	else
		slope = dabs((p1->y - p2->y) / (p1->x - p2->x));
	if (slope < 1)
		put_line_steap(data, p1, p2, color);
	else
		put_line_gentle(data, p1, p2, color);
}

void	draw_cross(mlx_image_t *img, int pos[2], int size)
{
	int	i;

	i = -size;
	while (i < size)
	{
		mlx_put_pixel(img, pos[0] + i, pos[1], RED);
		mlx_put_pixel(img, pos[0], pos[1] + i, RED);
		i++;
	}
}
