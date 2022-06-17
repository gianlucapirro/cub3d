/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 11:06:51 by gpirro        #+#    #+#                 */
/*   Updated: 2021/10/25 16:46:01 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*storage;
	int		i;

	i = 0;
	storage = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			storage = (char *) &str[i];
		i++;
	}
	if (str[i] == (char)c)
		storage = (char *) &str[i];
	return (storage);
}
