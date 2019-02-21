/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:41:17 by jochang           #+#    #+#             */
/*   Updated: 2019/02/20 15:41:18 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_placevalue(int n)
{
	int count;

	count = !n ? 1 : 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		sign;
	int		len;

	sign = (nbr >= 0 ? 1 : -1);
	len = ft_placevalue(nbr) + (sign >= 0 ? 0 : 1);
	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	len--;
	while (nbr)
	{
		str[len] = (nbr % 10) * sign + '0';
		nbr /= 10;
		len--;
	}
	if (sign == -1)
		str[len] = '-';
	return (str);
}
