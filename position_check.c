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

// Shifting back to beggining of board we can subtract the smallest X value from all pieces to arrive back at the original x values
// Y will never have to shift back up.

int		**shift_positions(char **board, int **positions, int count, int count2)
{
	int iter;
	int iter2;

	iter = 0;
	if (positions[count][count2] == '\0')
		return (NULL);
	else if (positions[count][count2] == '\n')
		return (y_shift(**board, int **positions)) // make this function
	else
	{
		while(iter < 4)
		{
			iter2 = 0;
			while (iter2 < 2)
			{
				positions[iter][iter2] += 1;
				iter2++;
			}
			iter++;
		}
	}
	return (positions);
}

/* check_positions
** check each position on the board to see if it is open
** if a position is not open call shift to shift the positions
** if there is no valid place to put the piece return NULL
** otherwise return the open positions
*/

int 	**check_positions(char **board, int **positions)
{
	int count;
	int count2;

	count = 0;
	while (count < 4)
	{
		count2 = 0;
		while (count2 < 2)
		{
			if (positions[count][count2] != '.')
			{
				positions = shift_positions(board, positions, count, count2);
				if (positions == NULL)
					return (NULL);
				count = 0;
				count2 = 0;
				continue ;
			}
			count2++;
		}
		count++;
	}
	return (positions);
}
