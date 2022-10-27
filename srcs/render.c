/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 13:35:24 by gpirro        #+#    #+#                 */
/*   Updated: 2022/10/27 19:07:33 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

unsigned int	get_pixel(mlx_texture_t *texture, float x, float y)
{
	u_int8_t	*dst;
	int			px;
	int			py;
	u_int32_t	color;

	px = (int)(texture->width * x);
	py = (int)(texture->height * y);
	dst = texture->pixels + (py * texture->width + px) * 4;
	((u_int8_t*)&color)[0] = dst[3];
	((u_int8_t*)&color)[1] = dst[2];
	((u_int8_t*)&color)[2] = dst[1];
	((u_int8_t*)&color)[3] = dst[0];
	return (color);
}

int	put_img_col_start(mlx_image_t *img, int x, int start)
{
	int	i;

	i = -1;
	while (++i < start)
		mlx_put_pixel(img, x, i, 0xFF0000FF);
	return (0);
}

int put_img_col_end(mlx_image_t *img, int x, int i)
{
	while (++i < WINDOW_HEIGHT)
		mlx_put_pixel(img, x, i, 0x0000FFFF);
	return (0);
}

void	put_img_column(t_config *config, mlx_image_t *img, t_ray *ray, int x)
{
	int				i;
	float			y;
	int				end;
	int				start;

	start = (WINDOW_HEIGHT - (int)(WINDOW_HEIGHT / ray->distance)) / 2;
	end = WINDOW_HEIGHT - start;
	put_img_col_start(img, x, start);
	i = start - 1;
	if (i < 0)
		i = 0;
	// printf("start: %f\n", ray->distance);
	while (++i < end && i < WINDOW_HEIGHT)
	{
		y = (float)(i - start) / (float)(end - start);
		// printf("a\n");
		unsigned int color = get_pixel((config->textures[ray->direction]), ray->pos_on_wall, y);
		// printf("%d %d\n", x, i);
		mlx_put_pixel(img, x, i, color);
	}
	put_img_col_end(img, x, end - 1);
	// printf("doei\n");
}

int	cast_all_lines(t_config *config, mlx_image_t *img)
{
	float	step_size;
	t_ray	ray;
	float	direction[2];
	int		i;

	i = 0;
	step_size = FOV / WINDOW_WIDTH;
	while (i < WINDOW_WIDTH)
	{
		direction[0] = config->direction[0];
		direction[1] = config->direction[1];
		rotate(direction, (i * step_size) + (FOV / -2));
		if (cast(config, &ray, direction, i * step_size - FOV / 2) != FAILED) {
			put_img_column(config, img, &ray, WINDOW_WIDTH - i - 1);
		}
		i++;
	}
	return (0);
}

/*
 This function renders every frame. 
 This function is called in a loop (mlx_hook_loop) 
 so that it will draw to the image for every frame.
 */
void	render_next_frame(void *tmp)
{
	t_config	*config;

	config = (t_config *)(tmp);	
	cast_all_lines(config, config->img); 
	// draw_minimap(config, config->img); 
	mlx_image_to_window(config->mlx, config->img, 0, 0);
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
		while (++h < dimensions[1]) {
			// printf("%d %d\n", x + w, y - h);
			mlx_put_pixel(img, x + w, y - h, color);
		}
	}
	return (SUCCES);
}
