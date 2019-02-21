/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:16:26 by jochang           #+#    #+#             */
/*   Updated: 2019/02/19 18:16:26 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	pgcd(int a, int b)
{
	int	i;
	int	max;

	i = 1;
	max = 0;
	while (i <= a && i <= b)
	{
		if (!(a % i) && !(b % i))
			max = i;
		i++;
	}
	return (max);
}

int	main(int ac, char **av)
{
	if (ac == 3)
		printf("%d", pgcd(atoi(av[1]), atoi(av[2])));
	printf("\n");
	return (0);
}
