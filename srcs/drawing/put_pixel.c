/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_pixel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 16:21:12 by gpirro        #+#    #+#                 */
/*   Updated: 2022/12/01 10:30:35 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	put_pixel(mlx_image_t *image, uint32_t x, uint32_t y, uint32_t color)
{
	if (x >= image->width || x < 0)
		return ;
	if (y >= image->height || y < 0)
		return ;
	mlx_put_pixel(image, x, y, color);
}
