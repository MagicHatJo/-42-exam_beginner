/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 04:14:20 by jochang           #+#    #+#             */
/*   Updated: 2018/05/17 04:30:30 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		wdmatch(char *s1, char *s2)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s1[i] && s2[k])
	{
		while (s2[k] && s1[i] != s2[k])
			k++;
		if (s1[i] == s2[k])
			i++;
	}
	return (s1[i] ? 0 : 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		if (wdmatch(argv[1], argv[2]))
			ft_putstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
