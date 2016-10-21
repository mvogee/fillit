/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 22:42:27 by mvogee            #+#    #+#             */
/*   Updated: 2016/10/20 22:42:29 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**create_board(int size)
{
	int		colcount;
	int		rowcount;
	char	**board;

	colcount = 0;
	rowcount = 0;
	while (colcount <= size)
	{
		board[colcount] = (char*)malloc(sizeof(char) * (size) + 1);
		colcount++;
	}
	//if (!board)
	//	error_call(3);
	while (rowcount <= size)
	{
		colcount = 0;
		while (colcount <= size)
		{
			board[rowcount][colcount] = '.';
			colcount++;
		}
		board[rowcount][colcount] = '\0';
		rowcount++;
	}
	return (board);
}

void	start_fillit(int *piecenums, int piececount)
{
	int		boardsize;
	char	**board;

	boardsize = ((piececount / 2) + 1);
	if (boardsize == 1)
		boardsize = 2;
	board = create_board(boardsize);
	printf("%s\n", board[0]);
	printf("%s\n",board[1]);
	(void)piecenums;
}

int main(void)
{
	int piece[5] = {1, 2, 3, 4, 5};
	start_fillit(piece, 2);
	return (0);
}