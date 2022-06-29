/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:35:24 by gpirro            #+#    #+#             */
/*   Updated: 2022/06/29 21:14:24 by gianlucapir      ###   ########.fr       */
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

int	put_img_column(t_data *img_data, t_ray *ray, int x)
{
	int	h;
	int	i;
	int	start;
	int	end;

	h = (int)(WINDOW_HEIGHT / ray->distance);
	start = (WINDOW_HEIGHT - h) / 2;
	end = WINDOW_HEIGHT - start;
	i = -1;
	while (++i < start)
		put_pixel(img_data, x, i, 0x000000FF);
	i = start - 1;
	while (++i < end)
	{
		if (ray->direction == NORTH)
			put_pixel(img_data, x, i, WHITE);
		else if (ray->direction == SOUTH)
			put_pixel(img_data, x, i, RED);
		else if (ray->direction == WEST)
			put_pixel(img_data, x, i, GREY);
		else if (ray->direction == EAST)
			put_pixel(img_data, x, i, PINK);
	}
	i = end - 1;
	while (++i < WINDOW_HEIGHT)
		put_pixel(img_data, x, i, 0x0000FF00);
	return (0);
}

int	cast_all_lines(t_config *config, t_data *img_data)
{
	float	step_size;
	t_ray	ray;
	float	direction[2];
	int		wall[3];
	float	pos[2];

	step_size = FOV / WINDOW_WIDTH;
	for (int i = 0; i < WINDOW_WIDTH; i++)
	{
		direction[0] = config->direction[0];
		direction[1] = config->direction[1];
		rotate(direction, (i * step_size) + (FOV / -2));
		if (cast(config, &ray, direction, i * step_size - FOV / 2) != FAILED) {
			put_img_column(img_data, &ray, WINDOW_WIDTH - i - 1);
			if (i % 10 != 0)
				continue;
			wall[0] = ray.x;
			wall[1] = ray.y;
			wall[2] = ray.direction;
			pos[0] = ray.real_x;
			pos[1] = ray.real_y;
			draw_wall(config, img_data, wall, RED);
			draw_minimap_line(config, img_data, pos, config->pos);
		}
	}
	return (0);
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

	config = (t_config *)(tmp);
	img_data.img = mlx_new_image(config->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img_data.addr = mlx_get_data_addr(img_data.img, &img_data.bits_per_pixel, \
	&img_data.line_length, &img_data.endian);
	cast_all_lines(config, &img_data);
	draw_minimap(config, &img_data);
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
