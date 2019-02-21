/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:20:25 by jochang           #+#    #+#             */
/*   Updated: 2019/02/20 16:20:26 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	**ft_split(char *str)
{
	char	**arr;
	int		i;
	int		numwords;
	int		wlen;

	numwords = ft_wordcount(str);
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