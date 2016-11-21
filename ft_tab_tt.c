/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_tt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:11:45 by liton             #+#    #+#             */
/*   Updated: 2016/11/21 15:52:57 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"
#include <stdlib.h>

tt_list		*in_ttmn(int nb_t, char **buff)
{
	int		i;
	tt_list	*new;

	i = 0;
	new = list_ttmn(nb_t);
	while (buff[i])
	{
		new->ttmn = reconvert(buff[i]);
	   	i++;
		new = new->next;
	}
	return (new);
}

tt_list		*add_right(tt_list *list)
{
	tt_list *new;
	tt_list *begin;

	begin = list;
	if (!(new = (tt_list*)malloc(sizeof(tt_list))))
		return (NULL);
	while (list->next)
		list = list->next;
	list->next = new;
	new->next = NULL;
	new->prev = list;
	list = begin;
	return (list);
}

tt_list		*list_ttmn(int nb_t)
{
	tt_list 	*new;
	tt_list 	*begin;
	int			i;

	i = 1;
	if(!(new = (tt_list*)malloc(sizeof(tt_list))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	begin = new;
	while (i < nb_t)
	{
		new = add_right(new);
		new = new->next;
		i++;
	}
	new = begin;
	return (new);
}
