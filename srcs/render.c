/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:35:24 by gpirro            #+#    #+#             */
/*   Updated: 2022/06/25 17:57:22 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/*
draws a pixel on the screen and checks if the x and y are still in the Image
 */
void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	y = WINDOW_HEIGHT - 1 - y;
	if (x > WINDOW_WIDTH - 1 || x < 0 || y > WINDOW_HEIGHT - 1 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
 This function renders every frame. 
 This function is called in a loop (mlx_hook_loop) 
 so that it will draw to the image for every frame.
 */
int	render_next_frame(void *tmp)
{
	t_data		img_data;
	t_config	*config;
	float		pos[2];

	config = (t_config *)(tmp);
	img_data.img = mlx_new_image(config->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img_data.addr = mlx_get_data_addr(img_data.img, &img_data.bits_per_pixel, \
	&img_data.line_length, &img_data.endian);
	draw_minimap(config, &img_data);
	cast(config, &img_data, pos);
	// first_intersect_h(config->pos, config->direction, pos);
	// draw_minimap_cross(config, &img_data, pos);
	// first_intersect_v(config->pos, config->direction, pos);
	// draw_minimap_cross(config, &img_data, pos);
	mlx_put_image_to_window(config->mlx, config->mlx_win, img_data.img, 0, 0);
	free(img_data.img);
	free(img_data.addr);
	return (SUCCES);
}

/**
 * @brief draws a rectangle, give pos (x/y), and the dimensions 
 * of the rectangle (width/height)
 * 
 * @param x 
 * @param y 
 * @param dimensions 
 * @param img_data 
 * @return int 
 */
int	draw_rectangle(int pos[2], int dimensions[2], t_data *img_data, int color)
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
			put_pixel(img_data, x + w, y + h, color);
	}
	return (SUCCES);
}

int	encode_rgb(u_int8_t r, u_int8_t g, u_int8_t b)
{
	return (r << 16 | g << 8 | b);
}
