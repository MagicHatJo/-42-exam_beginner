/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 23:14:24 by jochang           #+#    #+#             */
/*   Updated: 2018/12/12 23:14:25 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	brainfuck(char *s)
{
	char	arr[2048] = {0};
	char	*p = &arr[0];
	int		depth = 0;

	while (*s)
	{
		switch (*s)
		{
			case '>': p++; break;
			case '<': p--; break;
			case '+': (*p)++; break;
			case '-': (*p)--; break;
			case '.': write(1, p, 1); break;
			case '[':
				if (!*p)
				{
					depth = 1;
					while (depth)
					{
						s++;
						if (*s == '[')
							depth++;
						else if (*s == ']')
							depth--;
					}
				}
				break;
			case ']':
				if (*p)
				{
					depth = 1;
					while (depth)
					{
						s--;
						if (*s == ']')
							depth++;
						else if (*s == '[')
							depth--;
					}
				}
				break;
			default: break;
		}
		s++;
	}
}

int		main(int ac, char **av)
{
	ac > 1 ? brainfuck(av[1]) : write(1, "\n", 1);
	return (0);
}
