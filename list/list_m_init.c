/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_m_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsiegers <jsiegers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/29 16:31:15 by jsiegers      #+#    #+#                 */
/*   Updated: 2022/05/11 11:36:21 by jsiegers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list_m	*list_m_init(void)
{
	t_list_m	*list;

	list = (t_list_m *)malloc(sizeof(t_list_m));
	if (list == NULL)
		return (NULL);
	list->len = 0;
	list->head = NULL;
	list->tail = NULL;
	return (list);
}
