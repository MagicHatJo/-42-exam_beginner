/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 21:00:07 by jochang           #+#    #+#             */
/*   Updated: 2018/05/16 21:14:13 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_times(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 96);
	if (c >= 'A' && c <= 'Z')
		return (c - 64);
	return (1);
}

void	ft_multiwrite(char c)
{
	int k;

	k = -1;
	while (++k < ft_times(c))
		write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc == 2)
		while (argv[1][++i])
			ft_multiwrite(argv[1][i]);
	write(1, "\n", 1);
	return (0);
}
