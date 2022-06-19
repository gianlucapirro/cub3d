/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:06:51 by gpirro            #+#    #+#             */
/*   Updated: 2022/06/18 13:32:06 by gianlucapir      ###   ########.fr       */
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
