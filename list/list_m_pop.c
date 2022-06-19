/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_m_pop.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsiegers <jsiegers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/29 16:31:05 by jsiegers      #+#    #+#                 */
/*   Updated: 2022/05/11 11:36:32 by jsiegers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	list_m_pop(t_list_m *list, void **val)
{
	t_node_m	*elem;

	if (list == NULL || list->head == NULL)
		return (1);
	elem = list->tail;
	list->tail = elem->prev;
	if (list->tail == NULL)
		list->head = NULL;
	else
		list->tail->next = NULL;
	list->len -= 1;
	*val = elem->value;
	free(elem);
	return (0);
}
