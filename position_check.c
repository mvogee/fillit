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

/* find_xshift
** finds the smallest x value of the positions
** 
*/
int		find_xshift(int **postiions)
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

// Shifting back to beggining of board we can subtract the smallest X value from all pieces to arrive back at the original x values
// Y will never have to shift back up.

int		**shift_positions(char **board, int **positions, int count, int count2)
{
	int iter;
	int xshift;

	iter = 0;
	if (positions[count][count2] == '\0')
		return (NULL);
	else if (positions[count][count2] == '\n') // shift y down 1 and reset x values to original
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
