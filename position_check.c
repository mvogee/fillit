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

/*
** check_for_bad_indexes
** - Checks each index making sure there are no values that will go beyond
** the board boundries to avoid segfaults
** RETURN: if everything is ok it will return positions unchanged
** otherwise will return
*/

int		**check_for_bad_indexes(char **board, int **positions)
{
	int count;
	int boardlen;

	count = 0;
	boardlen = get_size(board[0]);
	while (count < 4)
	{
		if (positions[count][0] >= boardlen)
			return (NULL);
		if (positions[count][1] >= boardlen &&
			positions[count][0] >= boardlen - 1)
			return (NULL);
		count++;
	}
	return (positions);
}

/*
** undo_place
** itterates through the positions replacing the positoins with .
** effectively picking up a piece
** RETURN: returns updated board with given piece positions taken off;
*/

char	**undo_place(char **board, int **positions)
{
	int iter;

	iter = 0;
	while (iter < 4)
	{
		board[positions[iter][0]][positions[iter][1]] = '.';
		iter++;
	}
	return (board);
}

/*
** find_xshift
** finds the smallest x value of the positions
*/

int		find_xshift(int **positions)
{
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

/*
** shift_positions
** - Checks that the piece is not at the last possible possitions
** - Determines whether or not to Y shift or X shift
** - RETURN: Executes shift and returns updated indexes
*/

int		**shift_positions(char **board, int **positions, int count)
{
	int iter;
	int xshift;

	iter = 0;
	if (board[positions[count][0]][positions[count][1]] == '\0')
		return (NULL);
	else if (board[positions[count][0]][positions[count][1]] == '\n')
	{
		xshift = find_xshift(positions);
		while (iter < 4)
		{
			positions[iter][1] -= xshift;
			positions[iter][0] += 1;
			iter++;
		}
	}
	else
	{
		while (iter < 4)
		{
			positions[iter][1] += 1;
			iter++;
		}
	}
	return (positions);
}

/*
** check_positions
** Called form place_piece in fillit.c
** check each position on the board to see if it is open
** if a position is not open call shift to shift the positions
** if there is no valid place to put the piece return NULL
** otherwise return the open positions
*/

int		**check_positions(char **board, int **positions)
{
	int count;

	count = 0;
	positions = check_for_bad_indexes(board, positions);
	if (positions == NULL)
		return (NULL);
	while (count < 4)
	{
		if (board[positions[count][0]][positions[count][1]] != '.')
		{
			positions = shift_positions(board, positions, count);
			positions = check_for_bad_indexes(board, positions);
			if (positions == NULL)
				return (NULL);
			count = -1;
		}
		count++;
	}
	return (positions);
}
