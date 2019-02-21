/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 01:16:07 by jochang           #+#    #+#             */
/*   Updated: 2018/05/17 01:28:21 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int a;
	int b;

	if (argc == 4)
	{
		a = atoi(argv[1]);
		b = atoi(argv[3]);
		if (argv[2][0] == '+')
			printf("%d", a + b);
		else if (argv[2][0] == '-')
			printf("%d", a - b);
		else if (argv[2][0] == '*')
			printf("%d", a * b);
		else if (argv[2][0] == '/')
			printf("%d", a / b);
		else if (argv[2][0] == '%')
			printf("%d", a % b);
	}
	printf("\n");
	return (0);
}
