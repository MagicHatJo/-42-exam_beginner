/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 21:17:49 by jochang           #+#    #+#             */
/*   Updated: 2018/05/16 21:31:49 by jochang          ###   ########.fr       */
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

	i = -1;
	if (argc == 2)
	{
		while (argv[1][++i])
		{
			if ((argv[1][i] >= 'A' && argv[1][i] <= 'Y') ||
				(argv[1][i] >= 'a' && argv[1][i] <= 'y'))
				ft_putchar(argv[1][i] + 1);
			else if (argv[1][i] =='z' || argv[1][i] == 'Z')
				ft_putchar(argv[1][i] - 25);
			else
				ft_putchar(argv[1][i]);
		}
	}
	write(1, "\n", 1);
	return (0);
}
