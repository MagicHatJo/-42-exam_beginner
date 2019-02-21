/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:50:59 by jochang           #+#    #+#             */
/*   Updated: 2019/02/20 15:51:00 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_free_head(t_list **l)
{
	t_list *tmp = (*l)->next;
	free((*l)->data);
	free(*l);
	*l = tmp;
}

void	ft_list_free(t_list *p, t_list *t)
{
	p->next = t->next;
	free(t->data);
	free(t);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	while (*begin_list && !((*cmp)(data_ref, (*begin_list)->data)))
		ft_list_free_head(begin_list);
	t_list	*tmp = *begin_list;
	t_list	*prev;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		if (tmp && !((*cmp)(data_ref, (tmp)->data)))
			ft_list_free(prev, tmp);
	}
}