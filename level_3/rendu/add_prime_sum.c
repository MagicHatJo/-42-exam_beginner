/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:31:31 by jochang           #+#    #+#             */
/*   Updated: 2018/05/17 16:11:28 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_simple_atoi(char *str)
{
	int		n;
	int		i;

	i = 0;
	n = 0;
	if (str[i] == '-')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n);
}

int		ft_prime(int n)
{
	int		i;

	i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (n);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	(n < 0 ? ft_putchar('-') : 1);
	n *= (n > 0 ? -1 : 1);
	(n <= -10 ? ft_putnbr(-( n / 10)) : 1);
	ft_putchar('0' - n % 10);
}

void	add_prime_sum(int n)
{
	int		total;
	int		i;

	i = 1;
	total = 0;
	if (n < 0)
		return ;
	while (++i <= n)
		total += ft_prime(i);
	ft_putnbr(total);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		add_prime_sum(ft_simple_atoi(argv[1]));
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
