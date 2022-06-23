/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:00:49 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/06/23 18:03:40 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief 
 * 
 * @param c 
 * @param fdistance 
 * @return int 
 */
int	init_camera(t_camera *c, float fdistance)
{
	matrix_calloc(3, 3, &(c->internal));
	c->internal->mat[0][0] = fdistance;
	c->internal->mat[1][1] = fdistance;
	c->internal->mat[2][2] = 1;
	matrix_calloc(4, 3, &(c->external));
	c->external->mat[0][0] = -1;
	c->external->mat[1][2] = 1;
	c->external->mat[2][1] = 1;
	c->external->mat[1][3] = -1700;
	return (SUCCES);
}

int	create_block(t_matrix	**tmp)
{
	t_matrix	*block;

	matrix_calloc(8, 3, &block);
	block->mat[0][0] = 2000;
	block->mat[1][0] = 20000;
	block->mat[2][0] = 0;

	block->mat[0][1] = -2000;
	block->mat[1][1] = 20000;
	block->mat[2][1] = 0;

	block->mat[0][2] = -2000;
	block->mat[1][2] = 30000;
	block->mat[2][2] = 0;

	block->mat[0][3] = 2000;
	block->mat[1][3] = 30000;
	block->mat[2][3] = 0;

	block->mat[0][4] = 2000;
	block->mat[1][4] = 20000;
	block->mat[2][4] = 4000;

	block->mat[0][5] = -2000;
	block->mat[1][5] = 20000;
	block->mat[2][5] = 4000;

	block->mat[0][6] = -2000;
	block->mat[1][6] = 30000;
	block->mat[2][6] = 4000;

	block->mat[0][7] = 2000;
	block->mat[1][7] = 30000;
	block->mat[2][7] = 4000;
	*tmp = block;
	return (SUCCES);
}

int	tranform_camera(t_camera *c, t_matrix *p)
{
	t_matrix	cam;
	t_matrix	res;

	// print_matrix(*(c->internal));
	// print_matrix(*(c->external));
	matmul(c->internal, c->external, &cam);
	print_matrix(cam);
	print_matrix(*p);
	matmul(&cam, p, &res);
	print_matrix(res);
	h2e(&res);
	print_matrix(res);
	return (SUCCES);
}

int	create_block_lines(t_matrix	*res)
{
	float	arr[12][2] = {
		{0, 1},
		{1, 2},
		{2, 3},
		{3, 0},
		{4, 5},
		{5, 6},
		{6, 7},
		{7, 4},
		{0, 4},
		{1, 5},
		{2, 6},
		{3, 7},
	};
}
