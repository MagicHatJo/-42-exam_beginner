/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 03:33:38 by jochang           #+#    #+#             */
/*   Updated: 2018/05/17 03:40:04 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	int		i;
	int		n;
	char	s[8];

	i = 0;
	n = (int)octet;
	while (n)
	{
		s[i] = num % 2 + '0';
		num /= 2;
		i++;
	}
	while (i < 8)
	{
		s[i] = '0';
		i++;
	}
	i = 0;
	while (i < 8)
	{
		write(1, &str[i], 1);
		i++;
	}
}

unsigned char	reverse_bits_magic(unsigned char octet)
{
	return ((octet * 0x0202020202ULL & 0x010884422010ULL) % 0x3ff);
}
