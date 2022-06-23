/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathmat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:21:13 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/06/23 17:55:48 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	matmul(t_matrix *a, t_matrix *b, t_matrix *res)
{
	int	i;
	int	j;
	int	k;

	if (a->w != b->h)
		return (FAILED);
	res->h = a->h;
	res->w = b->w;
	alloc_2d_array(res->w, res->h, sizeof(float), (void ***)&(res->mat));
	i = -1;
	while (++i < res->h)
	{
		j = -1;
		while (++j < res->w)
		{
			k = -1;
			res->mat[i][j] = 0;
			while (++k < a->w)
				res->mat[i][j] += a->mat[i][k] * b->mat[k][j];
		}
	}
	return (SUCCES);
}

/**
 * @brief euclidian to homogeneous
 * add one more row matrix
 */
int	e2h(t_matrix *a)
{
	int		x;
	int		y;
	float	**tmp;
	float	*nrow;

	a->h = a->h + 1;
	tmp = a->mat;
	a->mat = pcalloc(sizeof(float *) * a->h);
	y = -1;
	while (++y < a->h - 1)
		a->mat[y] = tmp[y];
	nrow = pcalloc(a->w * sizeof(float));
	x = -1;
	while (++x < a->w)
		nrow[x] = 1;
	a->mat[y] = nrow;
	free(tmp);
	return (SUCCES);
}

/**
 * @brief homogeneus to euclidean
 * remove last row in matrix by dividing every x element in y row
 * according to last row matching x element
 * height = height - 1
 * @param a 
 * @return int 
 */
int	h2e(t_matrix *a)
{
	int		x;
	int		y;

	if (a->h <= 1)
		return (FAILED);
	a->h = a->h - 1;
	x = -1;
	while (++x < a->w)
	{
		y = -1;
		while (++y < a->h)
			a->mat[y][x] = a->mat[y][x] / a->mat[a->h][x];
	}
	free(a->mat[y]);
	return (SUCCES);
}
