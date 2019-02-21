/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:21:18 by jochang           #+#    #+#             */
/*   Updated: 2019/02/19 18:21:19 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define IS_DIGIT(x) (x >= '0' && x <= '9') ? 1 : 0

int		ft_atoi(char *s)
{
	int	n;

	n = 0;
	while (*s && IS_DIGIT(*s))
	{
		n *= 10;
		n += ((*s) - 48);
		s++;
	}
	return (n);
}

void	print_from(char *t, int i)
{
	while (t[i])
		write(1, &t[i++], 1);
}

void	print_hex(int n)
{
	char	*hex = "0123456789abcdef";
	char	tmp[15] = {0};
	int		i = 13;

	if (!n)
		write(1, "0", 1);
	while (n)
	{
		tmp[i] = hex[n % 16];
		n /= 16;
		i--;
	}
	print_from(tmp, ++i);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	write(1, "\n", 1);
	return (0);
}
