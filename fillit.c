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

char	**place_piece(char **board, int piecnum)
{

}

/* start_slove
** RECURSIVE
** - Places the current piece on the board.
** - As long as we still have pieces to place continue.
** - If failed to find a place to put piece return to previous piece or if 
** no solution is possible return -1 to start fillit to try a bigger board.
** - As long as piece is placeable move on to the next piece using recursion.
** - If we end up back poped back to the current piece move the piece and try again.
** RETURN: -1 on failure otherwise will continue recusing and exit on success.
*/

int		start_solve(int *piecenums, char **board, int piececount, int count)
{
	int solvable; // set so that we can return when appropriate
	int x; // itterator for position to attemp to place the piece when we need to move it

	solvable = 0;
	x = 0;
	board = place_piece(board, piecenums[count], x);
	while (count < piececount)
	{
		if (board == NULL)
			return (-1);
		solvable = start_solve(piecenums, board, piececount, count + 1);
		board = move_piece(count, x);
		x++;
	}
	print_result(board);
	//free(board) // make sure you find out how to free 2d array correctly
	exit(SUCCSESS);
	return (1);
}

/* USAGE: create_baord((square side length), 0, 0)
** -create_board creats the board based on the size given
** - RETURN: 2d array filled with '.' each row ending in \0
** ALWAYS PASS COLCOUNT AND ROWCOUNT AS 0
** MODIFIED SHOULD STILL BE WORKING.
*/

char	**create_board(int size, int colcount, int rowcount)
{
	char	**board;

	board = (char **)malloc(sizeof(char *) * size);
	while (colcount < size)
	{
		board[colcount] = (char *)malloc(sizeof(char) * size + 2);
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
		board[rowcount][colcount] = '\n';
		board[rowcount][colcount + 1] = '\0';
		rowcount++;
	}
	board[rowcount][colcount] = '\0';
	return (board);
}

/* start_fillit
** KICKOFF FUCNTION
** - Calculates the minimum boardsize possible
** so that we dont waste time
** -this will not work with 29 or more pieces but we dont need to
** ever deal with more than 26.
** - Creates the inital board calling create_board
** passes board and piece enums to solving functon
*/

void	start_fillit(int *piecenums, int piececount)
{
	int		boardsize;
	char	**board;
	int		solved;

	solved = 0;
	if (piececount < 16)
		boardsize = ((piececount / 2) + 1);
	else
		boardsize = (((piececount - (piececount / 4)) / 2) + 1);
	if (boardsize == 1)
		boardsize = 2;
	while (solved != 1)
	{	
		board = create_board(boardsize, 0, 0);
		solved = start_solve(piecenums, board, piececount, 0);
		if (solved == -1)
		{
			//free(board); figure out how to correctly free double pointer
			boardsize++;
		}
		if (solved == 1)
			exit(SUCCSESS);
		//free(board); figure out how to correctly free double pointer
	}

	int count = 0;	//REMOVE THIS LOOP; PRINTF TEST PRINTING LOOP;
	while (count < boardsize)
	{
		printf("%s\n",board[count]);
		count++;
	} // END OF LOOP TO REMOVE
}
// DELETE THIS MAIN
int main(void)
{
	int piece[5] = {1, 2, 3, 4, 5};
	start_fillit(piece, 11);
	return (0);
}