/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 19:23:51 by jochang           #+#    #+#             */
/*   Updated: 2018/05/17 19:33:16 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ' ? 1 : 0);
}

void	epur_str(char *s)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s) - 1;
	while (ft_isspace(s[i]))
		i++;
	while (ft_isspace(s[len]))
		len--;
	while (i <= len)
	{
		if (ft_isspace(s[i]))
		{
			while (ft_isspace(s[i]))
				i++;
			write(1, " ", 1);
		}
		if (s[i] && !ft_isspace(s[i]))
			write(1, &s[i], 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}
