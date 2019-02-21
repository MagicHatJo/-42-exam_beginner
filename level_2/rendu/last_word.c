/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 03:14:47 by jochang           #+#    #+#             */
/*   Updated: 2018/05/17 03:24:16 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ' ? 1 : 0);
}

int		main(int argc, char **argv)
{
	int		len;
	int		i;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]) - 1;
		while (ft_isspace(argv[1][len]))
			len--;
		i = len;
		while (i > 0 && !ft_isspace(argv[1][i - 1]))
			i--;
		while (i <= len)
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
