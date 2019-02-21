/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:14:13 by jochang           #+#    #+#             */
/*   Updated: 2019/02/19 19:14:13 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

# define IS_SPACE(x) x == '\t' || x == '\n' || x == '\v' || x == '\f' || x == '\r' || x == ' ' ? 1 : 0
# define TO_LOWER(x) (x >= 'A' && x <= 'Z' ? x + 32 : x)
# define TO_UPPER(x) (x >= 'a' && x <= 'z' ? x - 32 : x)

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	str_capitalizer(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		ft_putchar((!i || IS_SPACE(s[i - 1])) ? TO_UPPER(s[i]) : TO_LOWER(s[i]));
}

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac > 1)
	{
		while (++i < ac)
		{
			str_capitalizer(av[i]);
			ft_putchar('\n');
		}
	}
	else
		ft_putchar('\n');
	return (0);
}
