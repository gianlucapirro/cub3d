/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:12:49 by gpirro            #+#    #+#             */
/*   Updated: 2022/06/18 13:32:06 by gianlucapir      ###   ########.fr       */
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
