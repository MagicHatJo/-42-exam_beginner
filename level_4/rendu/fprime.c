/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:30:11 by jochang           #+#    #+#             */
/*   Updated: 2019/02/20 15:30:27 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		gnf(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (!(n % i))
			return (i);
	}
	return (n);
}

void	fprime(int n)
{
	int	f;
	while ((f = gnf(n)) != n)
	{
		printf("%d*", f);
		n /= f;
	}
	printf("%d", n);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
