/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 19:12:49 by gpirro        #+#    #+#                 */
/*   Updated: 2021/10/25 20:05:55 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	size;

	if (!s)
		return (0);
	i = 0;
	size = ft_strlen(s);
	if (len > size)
		len = size;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	while (i < len && start < size)
	{
		new[i] = s[i + start];
		i++;
	}
	new[i] = 0;
	return (new);
}
