/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:16:24 by gpirro            #+#    #+#             */
/*   Updated: 2022/06/25 14:35:05 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/*
 Takes a double x and returns the absolute value of the number
 */
static double	dabs(double x)
{
	if (x < 0)
		return (x * -1);
	else
		return (x);
}

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
static void	put_line_steap(t_data *data, t_point *p1, t_point *p2)
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
		put_pixel(data, x1, (int)y1, 0xFFFFFF);
	}
}

/*
 This function is used when the slope is bigger than 1
 to draw a gentle line
 */
static void	put_line_gentle(t_data *data, t_point *p1, t_point *p2)
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
		put_pixel(data, (int)x1, y1, 0xFFFFFF);
	}
}

/*
 Uses the putpixel function to draw a line. If the slope is
 bigger than 1 it will use the function put_line_gentle else it will use
 put_line_steap to draw the line
 */
void	draw_line(t_data *data, t_point *p1, t_point *p2)
{
	double	slope;

	if ((int)p1->x == (int)p2->x && (int)p1->y == (int)p2->y)
		return ;
	else if ((int)p1->x == (int)p2->x)
		slope = 1;
	else
		slope = dabs((p1->y - p2->y) / (p1->x - p2->x));
	if (slope < 1)
		put_line_steap(data, p1, p2);
	else
		put_line_gentle(data, p1, p2);
}

void	draw_cross(t_data *img_data, int pos[2], int size)
{
	int	i;

	i = -size;
	while (i < size)
	{
		put_pixel(img_data, pos[0] + i, pos[1], RED);
		put_pixel(img_data, pos[0], pos[1] + i, RED);
		i++;
	}
}