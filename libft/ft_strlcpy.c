/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 14:02:44 by gpirro        #+#    #+#                 */
/*   Updated: 2021/10/15 17:36:59 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *des, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
		return (ft_strlen((char *)src));
	while (i < (size - 1) && src[i])
	{
		des[i] = src[i];
		i++;
	}
	des[i] = '\0';
	return (ft_strlen((char *)src));
}
