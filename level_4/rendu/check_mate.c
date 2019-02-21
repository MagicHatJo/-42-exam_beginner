/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:41:34 by jochang           #+#    #+#             */
/*   Updated: 2019/02/20 14:41:35 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define IS_PIECE(x) (x == 'P' || x == 'B' || x == 'R' || x == 'Q' || x == 'K')
#define KING_CHECK(x) if (x == 'K') { ft_putstr("Success"); return (1); }

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int		check_pawn(int size, char **board, int y, int x)
{
	if (y > 0)
	{
		y--;
		if ((x - 1 >= 0 && board[y][x - 1] == 'K') ||
			(x + 1 < size && board[y][x + 1] == 'K'))
		{
			ft_putstr("Success");
			return (1);
		}
	}
	return (0);
}

int		check_bishop(int size, char **board, int y, int x)
{
	for (int i = 1; x - i >= 0 && y + i < size; i++)
		if (IS_PIECE(board[y + i][x - i]))
		{
			KING_CHECK(board[y + i][x - i]);
			break;
		}
	for (int i = 1; x + i < size && y + i < size; i++)
		if (IS_PIECE(board[y + i][x + i]))
		{
			KING_CHECK(board[y + i][x + i]);
			break;
		}
	for (int i = 1; x - i >= 0 && y - i >= 0; i++)
		if (IS_PIECE(board[y - i][x - i]))
		{
			KING_CHECK(board[y - i][x - i]);
			break;
		}
	for (int i = 1; x + i < size && y - i >= 0; i++)
		if (IS_PIECE(board[y - i][x + i]))
		{
			KING_CHECK(board[y - i][x + i]);
			break;
		}
	return (0);
}

int		check_rook(int size, char **board, int y, int x)
{
	for (int i = 1; y + i < size; i++)
		if (IS_PIECE(board[y + i][x]))
		{
			KING_CHECK(board[y + i][x]);
			break;
		}
	for (int i = 1; y - i >= 0; i++)
		if (IS_PIECE(board[y - i][x]))
		{
			KING_CHECK(board[y - i][x]);
			break;
		}
	for (int i = 1; x + i < size; i++)
		if (IS_PIECE(board[y][x + i]))
		{
			KING_CHECK(board[y][x + i]);
			break;
		}
	for (int i = 1; x - i >= 0; i++)
		if (IS_PIECE(board[y][x - i]))
		{
			KING_CHECK(board[y][x - i]);
			break;
		}
	return (0);
}

void	check_mate(int size, char **board)
{
	for (int y = 0; y < size; y++)
		for (int x = 0; x < size; x++)
		{
			if (board[y][x] == 'P')
			{
				if (check_pawn(size, board, y, x))
					return;
			}
			else if (board[y][x] == 'B')
			{
				if (check_bishop(size, board, y, x))
					return;
			}
			else if (board[y][x] == 'R')
			{
				if (check_rook(size, board, y, x))
					return;
			}
			else if (board[y][x] == 'Q')
			{
				if (check_bishop(size, board, y, x) || check_rook(size, board, y, x))
					return;
			}
		}
	ft_putstr("Fail");
}

int		main(int ac, char **av)
{
	if (ac > 1)
		check_mate(ac - 1, &av[1]);
	ft_putstr("\n");
}
