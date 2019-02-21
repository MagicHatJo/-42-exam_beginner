/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 02:35:48 by jochang           #+#    #+#             */
/*   Updated: 2018/05/17 03:11:00 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	inter(char *s1, char *s2)
{
	int		i;
	int		k;
	int		j;
	int		t;

	i = 0;
	while (s1[i])
	{
		k = 0;
		j = -1;
		t = 0;
		while (s2[k] && s2[k] != s1[i])
			k++;
		if (s2[k])
		{
			while(++j < i)
				t += (s1[j] == s1[i] ? 1 : 0);
			if (!t)
				write(1, &s2[k], 1);
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
