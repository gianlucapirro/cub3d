/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_m_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:27:53 by jsiegers          #+#    #+#             */
/*   Updated: 2022/06/19 11:32:50 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	list_m_free(t_list_m *list, int freeobj)
{
	t_node_m	*elem;
	t_node_m	*next;

	if (list == NULL)
		return (1);
	elem = list->head;
	while (elem)
	{
		if (freeobj)
			free(elem->value);
		next = elem->next;
		free(elem);
		elem = next;
	}
	free(list);
	return (0);
}
