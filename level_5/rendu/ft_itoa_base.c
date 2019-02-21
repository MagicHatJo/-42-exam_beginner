/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 23:36:38 by jochang           #+#    #+#             */
/*   Updated: 2018/12/12 23:36:39 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *s)
{
	int		i = 0;

	while (s[i])
		i++;
	return (i);
}

char	*ft_strrev(char *s)
{
	int		i = 0;
	int		k = ft_strlen(s) - 1;

	while (i < k)
	{
		s[i] ^= s[k];
		s[k] ^= s[i];
		s[i] ^= s[k];
		i++;
		k--;
	}
	return (s);
}

char	*ft_itoa_base(int value, int base)
{
	char	*hex = "0123456789ABCDEF";
	char	*total = (char*)malloc(13);
	int		i = 0;
	int		n = 1;

	if (!value)
	{
		total[0] = '0';
		total[1] = '\0';
		return (total);
	}
	if (value < 0)
		n = -1;
	while (value)
	{
		total[i] = hex[(value * n) % base];
		value /= base;
		i++;
	}
	if (n == -1 && base == 10)
	{
		total[i] = '-';
		i++;
	}
	total[i] = '\0';
	return (ft_strrev(total));
}
