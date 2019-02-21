/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:30:12 by jochang           #+#    #+#             */
/*   Updated: 2018/12/12 17:30:13 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	hidenp(char *s1, char *s2)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s1[i])
		return (1);
	while (s1[i])
	{
		if (!s2[k])
			return (0);
		if (s1[i] == s2[k])
			i++;
		k++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		write(1, hidenp(av[1], av[2]) ? "1" : "0", 1);
	write(1, "\n", 1);
	return (0);
}
