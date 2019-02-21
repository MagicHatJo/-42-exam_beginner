/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 20:08:20 by jochang           #+#    #+#             */
/*   Updated: 2018/05/17 20:18:40 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_rrange(int start, int end)
{
	int		*arr;
	int		range;
	int		i;

	i = start;
	range = (start > end ? start - end : end - start) + 1;
	if (!(arr = (int*)malloc(sizeof(int) * range)))
		return (NULL);
	while (i <= range)
	{
		if (start > end)
			arr[i] = end + i;
		else
			arr[i] = end - i;
		i++;
	}
	return (arr);
}
