/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:21:13 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/06/22 17:37:00 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	matmul(t_matrix a, t_matrix b, t_matrix *res)
{
	int	i;
	int	j;
	int	k;

	if (a.w != b.h)
		return (FAILED);
	res->h = a.h;
	res->w = b.w;
	alloc_2d_array(res->w, res->h, sizeof(float), &(res->mat));
	i = -1;
	while (++i < res->h)
	{
		j = -1;
		while (++j < res->w)
		{
			k = -1;
			res->mat[i][j] = 0;
			while (++k < a.w)
				res->mat[i][j] += a.mat[i][k] * b.mat[k][j];
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
	nrow = pcalloc(a->w * sizeof(float));
	x = -1;
	while (++x < a->w)
		nrow[x] = 1;
	a->mat = pcalloc(sizeof(float) * a->h);
	y = -1;
	while (++y < a->h - 1)
		a->mat[y] = tmp[y];
	a->mat[y] = nrow;
	free(tmp);
	return (SUCCES);
}

/**
 * @brief euclidian to homogeneous
 * add one more row matrix
 */
int	e2h(t_matrix *a, t_matrix *r)
{
	int	x;
	int	y;

	r->h = a->h + 1;
	r->w = a->w;
	alloc_2d_array(r->w, r->h, sizeof(float), &(r->mat));
	y = -1;
	while (++y < a->h)
	{
		x = -1;
		while (++x < a->w)
			r->mat[y][x] = a->mat[y][x];
	}
	x = -1;
	while (++x < r->w)
		r->mat[y][x] = (float)1;
	return (SUCCES);
}

int	h2e(t_matrix *a, t_matrix *r)
{
	int	x;
	int	y;

	if (r->h <= 1)
		return (FAILED);
	r->h = a->h - 1;
	r->w = a->w;
	alloc_2d_array(r->w, r->h, sizeof(float), &(r->mat));
	x = -1;
	while (++x < a->w)
	{
		y = -1;
		while (++y < r->h)
			r->mat[y][x] = a->mat[y][x] / a->mat[a->h - 1][x];
	}
	return (SUCCES);
}