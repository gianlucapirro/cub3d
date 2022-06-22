/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 09:33:37 by hthomas           #+#    #+#             */
/*   Updated: 2022/06/22 17:37:43 by gianlucapir      ###   ########.fr       */
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
# include <mlx.h>
# include <list.h>
# include <gnl.h>
# include <math.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_config
{
	int		**map;
	int		dimensions[2];
	int		player_size[2];
	int		block_size[2];
	float	pos[2];
	void	*mlx;
	void	*mlx_win;
}	t_config;

typedef struct s_matrix
{
	float	**mat;
	int		w;
	int		h;
}	t_matrix;

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
	INVALID_MAP
}	t_status;

typedef enum s_direction
{
	NORH,
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

# define GREY			0x00808080
# define RED			0x00FF0000
# define WHITE			0x00FFFFFF
# define PINK			0x00FF1493
# define BLACK			0x00000000

# define WINDOW_WIDTH 1300
# define WINDOW_HEIGHT 1000
# define PI 3.14159

void	exit_error(char *msg, int exitcode);
void	*pcalloc(size_t	size);

int		is_valid_c(char c);
void	print_maparray(int dimensions[2], int **map);
int		parse(char *fn, t_config *config);
void	get_fn(char **fn, char *argv[]);
void	error_handling(int argc, t_config *config);
int		render_next_frame(void *tmp);
int		draw_minimap(t_config *config, t_data *img_data);
int		draw_rectangle(int pos[2], int dimensions[2], \
		t_data *img_data, int color);
int		encode_rgb(u_int8_t r, u_int8_t g, u_int8_t b);
int		get_start_pos(t_config *config);
int		key_press(int keycode, t_config	*config);
int		is_start_pos(char c);
int		alloc_2d_array(int w, int h, int size, void ***array);
int		matmul(t_matrix a, t_matrix b, t_matrix *res);
void	draw_line(t_data *data, t_point *p1, t_point *p2);
void	put_pixel(t_data *data, int x, int y, int color);

int		h2e(t_matrix *a);
int		e2h(t_matrix *a);

int		print_matrix(t_matrix a);

#endif
