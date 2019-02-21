/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 19:35:42 by jochang           #+#    #+#             */
/*   Updated: 2018/05/17 19:49:44 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ishex(char c)
{
	return ((c >= '0' && c <= '9') ||
			(c >= 'a' && c <= 'f') ||
			(c >= 'A' && c <= 'F') ? 1 : 0);
}

int		ft_baseten(char c)
{
	if (c >= 'A' && c <= 'F')
		return (c - 54);
	if (c >= 'a' && c <= 'f')
		return (c - 86);
	if (c >= '0' && c <= '9')
		return (c - 48);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int		i;
	int		n;
	int		sign;

	n = 0;
	sign = (str[0] == '-' ? -1 : 1);
	i = (sign > 0 ? 0 : 1);
	while (ft_ishex(str[i]))
	{
		n = n * 10 + ft_baseten(str[i]);
		i++;
	}
	return (n * sign);
}
