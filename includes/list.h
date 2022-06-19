/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:19:09 by jsiegers          #+#    #+#             */
/*   Updated: 2022/06/19 11:32:05 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
typedef struct s_node_m
{
	void			*value;
	struct s_node_m	*next;
	struct s_node_m	*prev;
}	t_node_m;

typedef struct s_list_m
{
	int			len;
	t_node_m	*head;
	t_node_m	*tail;
}	t_list_m;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Function: list_i_init                                                     */
/*                                                                           */
/* Description:                                                              */
/*      This function creates an empty list, the list is double linked. The  */
/*      list has a head, this contains a pointer to the first element in the */
/*      list. The list also has a tail that points to the last element. The  */
/*      amount of elements in the list starts at 0.                          */
/*                                                                           */
/* Returns:                                                                  */
/*      A pointer to the list object.                                        */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
t_list_m	*list_m_init(void);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Function: list_i_free                                                     */
/*                                                                           */
/* Description:                                                              */
/*      This function frees the list, all elements in the list are freed and */
/*      the list struct is also freed.                                       */
/*                                                                           */
/* list:                                                                     */
/*      A pointer to the list struct that has to be freed.                   */
/*                                                                           */
/* Returns:                                                                  */
/*      1 if the freeing fails and 0 if all succeeded.                       */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int			list_m_free(t_list_m *list, int freeobj);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Function: list_i_add                                                      */
/*                                                                           */
/* Description:                                                              */
/*      This function adds an element to the specified listd.                */
/*                                                                           */
/* list:                                                                     */
/*      A pointer to the list where the integer is added too.                */
/*                                                                           */
/* num:                                                                      */
/*      The integer that has to be added to the list.                        */
/*                                                                           */
/* Returns:                                                                  */
/*      0 if succeeded and 1 if the adding fails.                            */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int			list_m_add(t_list_m *list, void *value);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Function: list_i_pop                                                      */
/*                                                                           */
/* Description:                                                              */
/*      This function removes the last element of the list and inserts it    */
/*      in the val parameter.                                                */
/*                                                                           */
/* list:                                                                     */
/*      The list that has to be popped from.                                 */
/*                                                                           */
/* val:                                                                      */
/*      A pointer to the integer where the value has to be written.          */
/*                                                                           */
/* Returns:                                                                  */
/*      0 if all succeeded, 1 in case of error.                              */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int			list_m_pop(t_list_m *list, void **val);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Function: list_i_to_array                                                 */
/*                                                                           */
/* Description:                                                              */
/*      Creates array with all elements in list, and inserts pointer into    */
/*      provided address.                                                    */
/*                                                                           */
/* list:                                                                     */
/*      The list to has to be turned into an array.                          */
/*                                                                           */
/* arr:                                                                      */
/*      A double pointer to the place where the array has to be written.     */
/*                                                                           */
/* Returns:                                                                  */
/*      The length of the array, 0 if the function fails.                    */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int			list_m_to_array(t_list_m *list, void ***arr);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Function: list_i_array_to_list                                            */
/*                                                                           */
/* Description:                                                              */
/*      Turns array into a list.                                             */
/*                                                                           */
/* arr:                                                                      */
/*      A pointer to the first element of the array to be used.              */
/*                                                                           */
/* len:                                                                      */
/*      The length of the specified length.                                  */
/*                                                                           */
/* Returns:                                                                  */
/*      A pointer to the created list, returns 0 if the creation failed.     */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
t_list_m	*list_m_array_to(void **arr, int len);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Function: list_i_reverse                                                  */
/*                                                                           */
/* Description:                                                              */
/*      Reverses the specified list by switching the next and previous       */
/*      variables of all the nodes.                                          */
/*                                                                           */
/* list:                                                                     */
/*      The list that has to be reversed.                                    */
/*                                                                           */
/* Returns:                                                                  */
/*      0 if the reversing succeeds and 1 if it fails.                       */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int			list_m_reverse(t_list_m	*list);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Function: list_i_popi                                                     */
/*                                                                           */
/* Description:                                                              */
/*      This function removes the element at the specified positions and     */
/*      inserts it into the integer pointed to by the val parameter.         */
/*                                                                           */
/* list:                                                                     */
/*      The list that has to be popped from.                                 */
/*                                                                           */
/* val:                                                                      */
/*      A pointer to the integer where the value has to be written.          */
/*                                                                           */
/* pos:                                                                      */
/*      The position of the element that has to be popped.                   */
/*                                                                           */
/* Returns:                                                                  */
/*      0 if all succeeded, 1 in case of error.                              */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int			list_m_popi(t_list_m *list, void **val, int pos);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Function: list_i_insert                                                   */
/*                                                                           */
/* Description:                                                              */
/*      This function inserts an elemeint in the specified list at the       */
/*      given position.                                                      */
/*                                                                           */
/* list:                                                                     */
/*      A pointer to the list where the integer is added too.                */
/*                                                                           */
/* num:                                                                      */
/*      The integer that has to be added to the list.                        */
/*                                                                           */
/* pos:                                                                      */
/*      The position of where the element has to be inserted.                */
/*                                                                           */
/* Returns:                                                                  */
/*      0 if succeeded and 1 if the adding fails.                            */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int			list_m_insert(t_list_m *list, void *value, int pos);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Function: list_m_get                                                      */
/*                                                                           */
/* Description:                                                              */
/*      This function get the element at the specifies positions.            */
/*                                                                           */
/* list:                                                                     */
/*      The list that has to be used.                                        */
/*                                                                           */
/* val:                                                                      */
/*      A pointer to the integer where the value has to be written.          */
/*                                                                           */
/* pos:                                                                      */
/*      The position of the element that is needed.                          */
/*                                                                           */
/* Returns:                                                                  */
/*      0 if all succeeded, 1 in case of error.                              */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int			list_m_get(t_list_m *list, void **val, int pos);

#endif
