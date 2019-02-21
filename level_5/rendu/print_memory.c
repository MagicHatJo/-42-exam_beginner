/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:31:16 by jochang           #+#    #+#             */
/*   Updated: 2018/12/12 17:31:19 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

void	print_memory(const void *addr, size_t size)
{
	const char	*hextemplate = "0123456789abcdef";
	char		*x = (char*)addr;
	char		hexbuf[40];
	char		asciibuf[17];
	int			hexiter = 0;
	int			asciiiter = 0;
	uint64_t	i;

	hexbuf[39] = '\0';
	for (i = 0;i < size;i++)
	{
		hexbuf[hexiter++] = hextemplate[(x[i] & 0xF0) >> 4];
		hexbuf[hexiter++] = hextemplate[x[i] & 0x0F];
		asciibuf[asciiiter++] = (x[i] >= 32 && x[i] <= 126 ? x[i] : '.');
		if ((!(asciiiter % 2)) && (asciiiter < 16))
			hexbuf[hexiter++] = ' ';
		if ((asciiiter == 16) || (size - 1 == i))
		{
			for (; hexiter < 39; hexiter++)
				hexbuf[hexiter] = ' ';
			for (; asciiiter < 17; asciiiter++)
				asciibuf[asciiiter] = '\0';
			write(1, &hexbuf[0], 40);
			write(1, " ", 1);
			write(1, &asciibuf[0], 16);
			write(1, "$\n", 2);
			hexiter = 0;
			asciiiter = 0;
		}
	}
}
