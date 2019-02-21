/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:44:03 by jochang           #+#    #+#             */
/*   Updated: 2019/02/19 16:44:04 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	hcf(unsigned int a, unsigned int b)
{
	unsigned int	i;
	unsigned int	max;

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

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (!a || !b)
		return (0);
	return ((a * b) / hcf(a, b));
}
