/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 11:06:17 by gpirro        #+#    #+#                 */
/*   Updated: 2021/10/15 17:35:29 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memset(void *string, int character, int len)
{
	int		i;
	char	*return_val;

	i = 0;
	return_val = (char *)string;
	while (i < len)
	{
		return_val[i] = character;
		i++;
	}
	return (return_val);
}
