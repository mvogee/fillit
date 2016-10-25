/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 19:35:43 by mvogee            #+#    #+#             */
/*   Updated: 2016/10/22 19:35:45 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**undo_place(char **board, int **positions)
{
	int iter;

	iter = 0;
	while (iter < 4)
	{
		board[positions[iter][0]][positions[iter][1]] = '.';
		iter++;
	}
	print_board(board);
	return (board);
}

/* find_xshift
** finds the smallest x value of the positions
** 
*/
int		find_xshift(int **positions)
{
	write(1, "entered find_xshift\n", 20); // REMOVE THIS LINE
	int xshift;
	int iter;

	xshift = 1000000;
	iter = 0;
	while (iter < 4)
	{
		if (positions[iter][1] < xshift)
			xshift = positions[iter][1];
		iter++;
	}
	return (xshift);
}

// Shifting back to beggining of board we can subtract the smallest X value from all pieces to arrive back at the original x values
// Y will never have to shift back up.

int		**shift_positions(char **board, int **positions, int count)
{
	write(1, "entered shift_positions\n", 24); // REMOVE THIS LINE
	int iter;
	int xshift;

	iter = 0;
	if (board[positions[count][0]][positions[count][1]] == '\0')
		return (NULL);
	else if (board[positions[count][0]][positions[count][1]] == '\n') // shift y down 1 and reset x values to original
	{
		xshift = find_xshift(positions); // find the value to shift x back
		while(iter < 4)
		{
			positions[iter][1] -= xshift; // shift x back
			positions[iter][0] += 1;	// iterate y value
			iter++;
		}
	}
	else // x shift
	{
		while(iter < 4)
		{
			positions[iter][1] += 1;
			iter++;
		}
	}
	write(1, "exit shift_positions\n", 21);
	return (positions);
}

/* check_positions 
** Called form place_piece in fillit.c
** check each position on the board to see if it is open
** if a position is not open call shift to shift the positions
** if there is no valid place to put the piece return NULL
** otherwise return the open positions
*/

int 	**check_positions(char **board, int **positions)
{
	write(1, "entered check_positions\n", 24); //REMOVE THIS LINE
	int count;

	count = 0;
	while (count < 4)
	{
		if (board[positions[count][0]][positions[count][1]] == '\0')
		{
			write(1, "NULL\n", 5);
				return (NULL);
		}
		count++;
	}
	count = 0;
	while (count < 4)
	{
		if (board[positions[count][0]][positions[count][1]] != '.')
		{
			positions = shift_positions(board, positions, count);
			if (positions == NULL)
				return (NULL);
			count = 0;
		}
		count++;
	}
	write(1,"exit check_positions\n", 21);
	return (positions);
}
