/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/04 09:33:37 by hthomas       #+#    #+#                 */
/*   Updated: 2022/12/01 10:23:27 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <time.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <unistd.h>
# include "libft.h"
# include <stdbool.h>
# include <MLX42.h>
# include <list.h>
# include <gnl.h>
# include <math.h>

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_config
{
	mlx_texture_t	*textures[4];
	mlx_image_t		*img;
	int				floorcolor;
	int				ceilingcolor;
	int				**map;
	int				dimensions[2];
	int				player_size[2];
	int				block_size[2];
	float			direction[2];
	float			pos[2];
	int				i;
	int				draw_minimap;
	mlx_t			*mlx;
}	t_config;

typedef struct s_matrix
{
	float	**mat;
	int		w;
	int		h;
}	t_matrix;

typedef struct s_camera
{
	t_matrix	*internal;
	t_matrix	*external;
}	t_camera;

typedef struct s_ray
{
	float	distance;
	int		direction;
	float	pos_on_wall;
	int		x;
	int		y;
	float	real_x;
	float	real_y;
}		t_ray;

typedef enum s_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum s_status
{
	SUCCES,
	FAILED,
	OPEN_ERROR,
	CLOSE_ERROR,
	PARSE_ERROR,
	MLX_ERROR,
	MALLOC_ERROR,
	ARGUMENT_ERROR,
	INVALID_MAP,
	NOT_FOUND
}	t_status;

typedef enum s_direction
{
	NORTH,
	WEST,
	SOUTH,
	EAST
}	t_direction;

typedef enum s_objects
{
	EMPTY,
	FLOOR,
	WALL,
	START_N,
	START_W,
	START_S,
	START_E,
	OTHER
}	t_objects;

typedef enum e_keys
{
	ARROW_R	= 124,
	ARROW_L	= 123,
	ARROW_U	= 125,
	ARROW_D	= 126,
	PAGE_U	= 116,
	PAGE_D	= 121,
	PLUS	= 24,
	ESC		= 53,
	MIN		= 27,
	Q		= 12,
	W		= 13,
	E		= 14,
	A		= 0,
	S		= 1,
	D		= 2
}	t_keys;

typedef enum e_textures
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
}	t_textures;

# define GREY			0x00808080
# define RED			0x00FF0000
# define WHITE			0x00FFFFFF
# define PINK			0x00FF1493
# define BLACK			0x00000000

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 800
# define PI 3.14159
# define FOV 60.0
# define PACE 0.13
# define INFINITY_INT 1000000
# define ROTATION_SPEED 2

//libft+
void	exit_error(char *msg, int exitcode);
void	*pcalloc(size_t	size);
float	deg_to_rad(float deg);

//utils
int		is_valid_c(char c);
int		is_start_pos(char c);
int		encode_rgb(int r, int g, int b);
int		ft_arr_len(char **arr);
int		check_empty_line(char *buffer);

//parsing
int		parse_textures(t_config *config, t_list_m *linesread, int len);
int		get_start_pos(t_config *config);
int		parse(char *fn, t_config *config);
void	get_fn(char **fn, char *argv[]);
void	print_maparray(int dimensions[2], int **map);

//error
void	error_handling(int argc, t_config *config);
int		can_be_opened(char *fn);

//minilibx+
void	render_next_frame(void *tmp);

//drawing
int		draw_wall(t_config *c, mlx_image_t *img_d, int wall[3], int color);
int		draw_rectangle(int pos[2], int dimensions[2], \
		mlx_image_t *img, int color);
void	draw_line(mlx_image_t *data, t_point *p1, t_point *p2, int color);
void	draw_cross(mlx_image_t *img, int pos[2], int size);
void	put_pixel(mlx_image_t *image, uint32_t x, uint32_t y, uint32_t color);

//events
void	key_press(mlx_key_data_t keycode, void *config);
void	print_maparray(int dimensions[2], int **map);
int		get_wall(t_config *config, float inter[2], int wall[3], t_ray *ray);
int		rotate(float vec[2], float deg);
int		cast(t_config *config, t_ray *ray, float direction[2], float angle);
int		first_intersect_v(float pos[2], float direc[2], float intersect[3]);
int		first_intersect_h(float pos[2], float direc[2], float intersect[3]);
int		rotate_player(t_config *config, float deg);
int		is_valid_pos(t_config	*config, float x, float y);

//render
void	put_img_column(t_config *config, mlx_image_t *img, t_ray *ray, int x);
int		get_closest_intersection(t_config *config, float *inter[2]);
float	fix_fish_eye(float pos[2], float inter[2], float direc[2]);
double	dabs(double x);
int		get_next_intersect(float vec[3], \
		float direc[2], float pos[2], int v_or_h);
int		free_array(char **arr);
float	calc_dist(float *p1, float *p2);
t_bool	intersect_to_wall(float direc[2], float inter[2], \
		int wall[3], int axis);
int		cast_all_lines(t_config *config, mlx_image_t *img);

//minimap
int		draw_minimap(t_config *config, mlx_image_t *img);
int		set_data_wall_ns(t_point *s, t_point *e, int wall[3]);
int		set_data_wall_ew(t_point *s, t_point *e, int wall[3]);
int		draw_minimap_cross(t_config *conf, mlx_image_t *img, float pos[2]);
int		draw_minimap_line(t_config *config, \
		mlx_image_t *img, float start[2], float end[2]);

#endif
