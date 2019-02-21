/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:17:15 by jochang           #+#    #+#             */
/*   Updated: 2019/02/19 19:17:16 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define IS_DIGIT(x) (x >= '0' && x <= '9') ? 1 : 0

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	write(1, s, 3);
}

void	ft_putnbr(int n)
{
	n > 9 ? ft_putnbr(n / 10) : 0;
	ft_putchar(n % 10 + 48);
}

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

void	tab_mult(int n)
{
	for (int i = 1; i < 10; i++)
	{
		ft_putnbr(i);
		ft_putstr(" x ");
		ft_putnbr(n);
		ft_putstr(" = ");
		ft_putnbr(i * n);
		ft_putchar('\n');
	}
}

int		main(int ac, char **av)
{
	if (ac > 1)
		tab_mult(ft_atoi(av[1]));
	else
		ft_putchar('\n');
	return (0);
}
