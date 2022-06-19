/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_m_array_to.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:26:34 by jsiegers          #+#    #+#             */
/*   Updated: 2022/06/19 11:39:22 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list_m	*list_m_array_to(void **arr, int len)
{
	t_list_m	*list;
	int			i;

	list = list_m_init();
	if (list == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		if (list_m_add(list, arr[i]) != 0)
		{
			list_m_free(list, 0);
			return (0);
		}
		i++;
	}
	return (list);
}
