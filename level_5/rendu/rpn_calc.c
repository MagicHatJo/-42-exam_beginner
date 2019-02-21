/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 23:57:25 by jochang           #+#    #+#             */
/*   Updated: 2018/12/12 23:57:26 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define IS_DIGIT(x) (x >= '0' || x <= '9') ? 1 : 0
#define IS_OPR(x) (x == '+' || x == '-' || x == '*' || x == '/' || x == '%') ? 1 : 0
#define IS_SPACE(x) (x == ' ') ? 1 : 0

int		do_math(int a, int b, char opr)
{
	switch (opr)
	{
		case '+': return (a + b);
		case '-': return (a - b);
		case '*': return (a * b);
		case '/': return (a / b);
		case '%': return (a % b);
		default: break;
	}
	return (0);
}

void	to_next(char **str)
{
	while (**str && !IS_SPACE(**str))
		(*str)++;
	if (**str)
		(*str)++;
}

int		rpn_calc(char *str)
{
	int		nums[2048] = {0};
	int		i = -1;
	int		a;
	int		b;

	while (*str)
	{
		if (IS_OPR(*str))
		{
			if (i < 1)
				return (0);
			a = nums[i];
			i--;
			b = nums[i];
			nums[i] = do_math(a, b, *str);
		}
		else if (IS_DIGIT(*str))
		{
			i++;
			nums[i] = atoi(str);
		}
		to_next(&str);
	}
	if (i == 0)
	{
		printf("%d\n", nums[i]);
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	if (ac != 2 || !rpn_calc(av[1]))
		printf("Error\n");
	return (0);
}
