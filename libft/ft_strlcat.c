/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 11:06:33 by gpirro        #+#    #+#                 */
/*   Updated: 2021/10/15 17:36:53 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destsize;
	size_t	srcsize;
	size_t	i;

	destsize = ft_strlen(dest);
	srcsize = ft_strlen((char *)src);
	i = 0;
	if (size == 0 || destsize >= size)
		return (srcsize + size);
	while (src[i] && i < size - destsize - 1)
	{
		dest[destsize + i] = src[i];
		i++;
	}
	dest[destsize + i] = '\0';
	return (srcsize + destsize);
}
