/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:10:07 by gpirro            #+#    #+#             */
/*   Updated: 2022/06/18 13:32:06 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	unsigned int	nr;
	int				neg;

	nr = 0;
	neg = 1;
	while ((*s >= '\t' && *s <= '\r') || *s == ' ' )
		s++;
	if (*s == '-')
		neg = -1;
	if (*s == '+' || *s == '-')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		if ((nr * 10 + (*s - '0')) < nr)
		{
			if (neg > 0)
				return (-1);
			return (0);
		}
		nr = nr * 10;
		nr = nr + (int)(*s - '0');
		s++;
	}
	return (nr * neg);
}
