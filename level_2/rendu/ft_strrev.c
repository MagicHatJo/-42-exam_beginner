/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 02:33:27 by jochang           #+#    #+#             */
/*   Updated: 2018/05/17 02:35:28 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		k;
	char	t;

	i = 0;
	k = ft_strlen(str) - 1;
	while (i < k)
	{
		t = str[i];
		str[i] = str[k];
		str[k] = t;
		i++;
		k++;
	}
	return (str);
}
