/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 11:06:10 by gpirro        #+#    #+#                 */
/*   Updated: 2021/10/25 19:36:32 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *str, int c, size_t nr)
{
	size_t	i;
	char	*array;

	i = 0;
	array = (void *)str;
	while (i < nr)
	{
		if (array[i] == (char)c)
			return (&array[i]);
		i++;
	}
	return (NULL);
}
