/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:02:59 by jochang           #+#    #+#             */
/*   Updated: 2019/02/20 18:03:02 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

static void		split(t_list *head, t_list **a, t_list **b)
{
	t_list	*slow;
	t_list	*fast;

	slow = head;
	fast = head->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*a = head;
	*b = slow->next;
	slow->next = NULL;
	return ;
}

static t_list	*merge_sorted(t_list *a, t_list *b, int (*cmp)(int, int))
{
	t_list	*result;

	result = NULL;
	if (!a)
		return (b);
	if (!b)
		return (a);
	if ((*cmp)(a->data, b->data))
	{
		result = a;
		result->next = merge_sorted(a->next, b, cmp);
	}
	else
	{
		result = b;
		result->next = merge_sorted(a, b->next, cmp);
	}
	return (result);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = lst;
	if (!head || !head->next)
		return (NULL);
	split(head, &a, &b);
	sort_list(a, cmp);
	sort_list(b, cmp);
	lst = merge_sorted(a, b, cmp);
	return (lst);
}
