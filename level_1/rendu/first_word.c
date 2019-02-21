/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 20:43:40 by jochang           #+#    #+#             */
/*   Updated: 2018/05/16 20:49:15 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ' ? 1 : 0);
}

int	main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while (ft_isspace(argv[1][i]))
			i++;
		while(argv[1][i] && !ft_isspace(argv[1][i]))
			write(1, &argv[1][i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
