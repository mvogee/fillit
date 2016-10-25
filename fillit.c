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

/* place_piece
** - Creates the letter that will represent the piece
** - Gets the index positions of the given piece
** - Finds the first place that the piece can be placed
** - Places the charid int the correct indexes and returns the updated board
*/
char	**place_piece(char **board, int **positions, int id)
{
	write(1, "entered place_piece\n", 20); // REMOVE THIS LINE
	char	charid;
	int		count;

	count = 0;
	charid = 'A' + id;
	write(1, "got positions\n", 14); // REMOVE THIS LINE
	// for (int i = 0; i < 4; i++)
	// {
	// 	printf("%d ", positions[i][0]);
	// 	printf("%d\t", positions[i][0]);
	// }
	positions = check_positions(board, positions);
	if (positions == NULL)
	{
		write(1, "place piece returnd null\n", 25); // REMOVE THIS LINE
		return (NULL);
	}
	while (count < 4)
	{
		board[positions[count][0]][positions[count][1]] = charid;
		count++;
	}
	print_board(board);
	write(1, "exit place_piece\n", 17); // REMOVE THIS LINE
	return (board);
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

	write(1, "entered start_solve\n", 20); // REMOVE THIS LINE
	int solvable; // set so that we can return when appropriate
	int **positions; // itterator for position to attemp to place the piece when we need to move it
printf("count1: %d\n", count); //REMOVE THIS LINE
printf("piececount: %d\n", piececount); //REMOVE THIS LINE
	if (count >= piececount)
	{
		print_board(board);
		write(1, "complete\n",9);
		exit(42);
	}
	solvable = 0;
	positions = get_positions(piecenums[count]);
	board = place_piece(board, positions, count);
	while (count < piececount)
	{
				printf("count2: %d\n", count); // REMOVE THIS LINE
		if (board == NULL)
			return (-1);
		solvable = start_solve(piecenums, board, piececount, count + 1);
		write(1, "backtracked\n", 12);
		// next three actions move positions and place the piece in the next open space.
		board = undo_place(board, positions);
		positions = check_positions(board, positions);
		positions = shift_positions(board, positions, 0);
		positions = check_positions(board, positions);
		if (positions == NULL)
			return (-1);
		board = place_piece(board, positions, count);
	}
	print_board(board);
	write(1, "complete\n",9);
	//free(board) // make sure you find out how to free 2d array correctly
	exit(42);
	return (1);
}

/* USAGE: create_board((square side length), 0, 0)
** -create_board creats the board based on the size given
** - RETURN: 2d array filled with '.' each row ending in \0
** ALWAYS PASS COLCOUNT AND ROWCOUNT AS 0
** WORKING.
*/

char	**create_board(int size, int colcount, int rowcount)
{
	write(1, "entered create_board\n", 21); // remove this line
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
		if (rowcount < size)
			board[rowcount][colcount] = '\n';
		board[rowcount][colcount + 1] = '\0';
		rowcount++;
	}
	write(1, "outside loop\n", 13); // REMOVE THIS LINE
	board[rowcount - 1][colcount] = '\0';
	write(1, "exit create board\n", 18); // REMOVE THIS LINE
	return (board);
}
//create board main
// int main(void)
// {
// 	char **board;
// 	int count;
// 	int count2;
// 	int size;

// 	count2 = 0;
// 	count = 0;
// 	size = 5;
// 	board = create_board(size, 0, 0);
	// while (count < size)
	// {
	// 	while(board[count][count2] != '\0')
	// 	{
	// 		write(1, &board[count][count2], 1);
	// 		count2++;
	// 	}
	// 	count++;
	// 	count2 = 0;
	// }
// 	return (0);
// }

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
	write(1, "entered start_fillit\n", 21); // REMOVE THIS LINE
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
			exit(10);
		//free(board); figure out how to correctly free double pointer
	}

	int count = 0;	//REMOVE THIS LOOP; PRINTF TEST PRINTING LOOP;
	while (count < boardsize)
	{
		printf("%s\n",board[count]);
		count++;
	} // END OF LOOP TO REMOVE
}
//DELETE THIS MAIN
int main(void)
{
	int piece[2] = {1, 3};
	start_fillit(piece, 2);
	return (0);
}