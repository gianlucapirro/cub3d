/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 11:22:56 by gpirro        #+#    #+#                 */
/*   Updated: 2021/10/15 17:35:09 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest2;
	const char	*src2;
	size_t		i;

	src2 = src;
	dest2 = dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest2 > src2)
	{
		while (n > 0)
		{
			dest2[n - 1] = src2[n - 1];
			n--;
		}
		return (dest);
	}
	i = 0;
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}
