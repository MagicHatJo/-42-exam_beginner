/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 22:49:23 by jochang           #+#    #+#             */
/*   Updated: 2018/05/16 23:05:57 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int i;

	if (argc == 4 && ft_strlen(argv[2]) == 1 &&
		ft_strlen(argv[3]) == 1)
	{
		i = -1;
		while (argv[1][++i])
		{
			if (argv[1][i] == argv[2][0])
				write(1, &argv[3][0], 1);
			else
				write(1, &argv[1][i], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
