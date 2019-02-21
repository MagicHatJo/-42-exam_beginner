/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 22:51:07 by jochang           #+#    #+#             */
/*   Updated: 2018/12/12 22:51:08 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_matching(char o, char c)
{
	return ((o == '(' && c == ')') ||
			(o == '[' && c == ']') ||
			(o == '{' && c == '}'));
}

int		brackets(char *str)
{
	char	stack[2048];
	int		i = -1;

	while (*str)
	{
		if (*str == '(' || *str == '[' || *str == '{')
			stack[++i] = *str;
		else if (*str == ')' || *str == ']' || *str == '}')
		{
			if (check_matching(stack[i], *str))
				i--;
			else
				return (0);
		}
		str++;
	}
	return (i == -1 ? 1 : 0);
}

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	while (++i < ac)
		brackets(av[i]) ? write(1, "OK\n", 3) : write(1, "Error\n", 6);
	i == 1 ? write(1, "\n", 1) : 0;
	return (0);
}
