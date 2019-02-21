/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 19:51:39 by jochang           #+#    #+#             */
/*   Updated: 2018/05/17 20:07:59 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = begin_list;
	if (begin_list)
	{
		while (ptr)
		{
			ptr = ptr->next;
			i++;
		}
	}
	return (i);
}
