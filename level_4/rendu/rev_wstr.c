/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:32:22 by jochang           #+#    #+#             */
/*   Updated: 2019/02/20 17:32:22 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

# define IS_SPACE(x) x == '\t' || x == '\n' || x == '\v' || x == '\f' || x == '\r' || x == ' ' ? 1 : 0

int		ft_wordcount(char const *s)
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		if (!(IS_SPACE(s[i])) && (i == 0 || IS_SPACE(s[i - 1])))
			count++;
	return (count);
}

int		ft_wordlen(char const *s)
{
	int i;

	i = 0;
	while (!(IS_SPACE(s[i])) && s[i])
		i++;
	return (i);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	if (!s || !(new = (char*)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (len--)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**ft_split(char *str, int numwords)
{
	char	**arr;
	int		i;
	int		wlen;

	if(!(arr = (char**)malloc((numwords + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	while (numwords--)
	{
		while (IS_SPACE(*str))
			str++;
		wlen = ft_wordlen(str);
		if (!(arr[i] = ft_strsub(str, 0, wlen)))
			return (NULL);
		str += wlen;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	rev_wstr(char *s)
{
	int		words = ft_wordcount(s);
	char	**arr = ft_split(s, words);
	int		i = words - 1;
	for (;i > 0; i--)
	{
		ft_putstr(arr[i]);
		write(1, " ", 1);
	}
	ft_putstr(arr[i]);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
