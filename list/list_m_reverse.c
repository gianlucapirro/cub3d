/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_m_reverse.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsiegers <jsiegers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/29 16:30:55 by jsiegers      #+#    #+#                 */
/*   Updated: 2022/05/11 11:36:44 by jsiegers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	list_m_reverse(t_list_m	*list)
{
	t_node_m	*elem;
	t_node_m	*buff;

	if (list == NULL)
		return (1);
	elem = list->head;
	while (elem)
	{
		buff = elem->next;
		elem->next = elem->prev;
		elem->prev = buff;
		elem = elem->prev;
	}
	buff = list->head;
	list->head = list->tail;
	list->tail = buff;
	return (0);
}
