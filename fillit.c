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

/* USAGE: create_baord((square side length), 0, 0)
** -create_board creats the board based on the size given
** - RETURN: 2d array filled with '.' each row ending in \0
** ALWAYS PASS COLCOUNT AND ROWCOUNT AS 0
** WORKING
*/

char	**create_board(int size, int colcount, int rowcount)
{
	char	**board;

	board = (char **)malloc(sizeof(char *) * size);
	while (colcount < size)
	{
		board[colcount] = (char *)malloc(sizeof(char) * size + 1);
		colcount++;
	}
	if (!board)
		error_call(3);
	while (rowcount < size)
	{
		colcount = 0;
		while (colcount < size)
		{
			board[rowcount][colcount] = '.';
			colcount++;
		}
		board[rowcount][colcount] = '\0';
		rowcount++;
	}
	return (board);
}

/* start_fillit
** KICKOFF FUCNTION
** - Calculates the minimum boardsize possible
** so that we dont waste time
** -this will not work with 29 or more pieces but we dont need to
** ever deal with more than 26.
** - Creates the inital board calling create_board
** - Gets array of placeable pieces
** passes board and pieces to solving functon
*/

void	start_fillit(int *piecenums, int piececount)
{
	int		boardsize;
	char	**board;

	if (piececount < 16)
		boardsize = ((piececount / 2) + 1);
	else
		boardsize = (((piececount - (piececount / 4)) / 2) + 1);
	if (boardsize == 1)
		boardsize = 2;
	board = create_board(boardsize, 0, 0);

	int count = 0;	//REMOVE THIS LOOP; PRINTF TEST PRINTING LOOP;
	while (count < boardsize)
	{
		printf("%s\n",board[count]);
		count++;
	} // END OF LOOP TO REMOVE
	(void)piecenums;
}
// DELETE THIS MAIN
int main(void)
{
	int piece[5] = {1, 2, 3, 4, 5};
	start_fillit(piece, 11);
	return (0);
}