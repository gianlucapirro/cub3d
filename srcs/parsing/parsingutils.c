/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:01:26 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/06/19 12:46:32 by gianlucapir      ###   ########.fr       */
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
