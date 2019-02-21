/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 23:07:26 by jochang           #+#    #+#             */
/*   Updated: 2018/05/16 23:21:56 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		i = -1;
		while (argv[1][++i])
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				ft_putchar(argv[1][i] + 32);
			else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				ft_putchar(argv[1][i] - 32);
			else
				ft_putchar(argv[1][i]);
		}
	}
	write(1, "\n", 1);
	return (0);
}
