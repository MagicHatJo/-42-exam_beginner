/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 02:16:58 by jochang           #+#    #+#             */
/*   Updated: 2018/05/17 02:33:03 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	i = -1;
	if (str = (char*)malloc(ft_strlen(src) + 1))
		return (NULL);
	while (src[++i])
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}
