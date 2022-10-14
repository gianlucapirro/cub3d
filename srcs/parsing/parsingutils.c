/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:01:26 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/10/14 09:15:42 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Checks if c is equal to N || W || S || E || 0 || 1
 * 
 * @param c 
 * @return if c is eqal to one of the above: return 1 else return 0
 * 
 */
int	is_valid_c(char c)
{
	if (c == 'N' || c == 'W' || c == 'S' || c == 'E' || c == '0' || c == '1')
		return (1);
	return (0);
}

/**
 * @brief protected malloc, Mallocs size into void *
 * if malloc fails exit with malloc failure. returns 
 * the malloced void *.
 * 
 * @param size 
 * @return void* 
 */
void	*pcalloc(size_t	size)
{
	void	*new;

	new = ft_calloc(1, size);
	if (!new)
		exit_error("pcalloc failed", MALLOC_ERROR);
	return (new);
}

/**
 * @brief Loops over map and prints every int.
 * the dimensions must be passed in format x-y
 * (dimensions[x][y]).
 * 
 * @param dimensions 
 * @param map 
 */
void	print_maparray(int dimensions[2], int **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < dimensions[1])
	{
		j = 0;
		while (j < dimensions[0])
		{
			printf("%d", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	check_empty_line(char *buffer)
{
	buffer = ft_strtrim(buffer, " ");
	if (!buffer)
		exit_error("Error\nMalloc failed", MALLOC_ERROR);
	if (ft_strncmp(buffer, "\n", 1) == 0)
	{
		free(buffer);
		return (true);
	}
	free(buffer);
	return (false);
}

int	ft_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
