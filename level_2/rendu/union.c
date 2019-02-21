/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 03:42:12 by jochang           #+#    #+#             */
/*   Updated: 2018/05/17 04:12:24 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		al_print(char *s, int i)
{
	int		j;
	int		c;

	j = -1;
	c = 0;
	while (++j < i)
		c += (s[i] == s[j] ? 1 : 0);
	return (c);
}


void	ft_union(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	int		t;

	i = 0;
	while (s1[i])
	{
		if (!al_print(s1, i))
			write(1, &s1[i], 1);
		i++;
	}
	k = 0;
	while (s2[k])
	{
		j = -1;
		t = 0;
		while (++j < i)
			t += (s2[k] == s1[j] ? 1 : 0);
		if (!(al_print(s2, k) + t))
			write(1, &s2[k], 1);
		k++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
