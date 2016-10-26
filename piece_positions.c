/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_positions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 18:53:24 by mvogee            #+#    #+#             */
/*   Updated: 2016/10/21 18:53:26 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** copy_positions
** copies positions and returns allocated strings with correct indexes
*/

static int	**copy_positions(int g_strt_pos[20][4][2], int piecenum)
{
	int count;
	int count2;
	int **ret;

	count = 0;
	ret = (int **)malloc(sizeof(int *) * 4);
	while (count < 4)
	{
		ret[count] = (int *)malloc(sizeof(int) * 2);
		count++;
	}
	count = 0;
	while (count < 4)
	{
		count2 = 0;
		while (count2 < 2)
		{
			ret[count][count2] = g_strt_pos[piecenum][count][count2];
			count2++;
		}
		count++;
	}
	return (ret);
}

/*
** get_positions
** starting coordinates of each piece placed nearest to the upper left corner of
** the board.
**
** each index i in g_strt_pos[i] represents one of the 19 possible tetraminos
** each index j in g_strt_pos[i][j] represents a row and column location of a
** square in the tetramino piece
*/

int			**get_positions(int piecenum)
{
	int	g_strt_pos[20][4][2];

	g_strt_pos = {
		{{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
		{{0, 0}, {0, 1}, {1, 0}, {1, 1}},
		{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
		{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
		{{0, 0}, {1, 0}, {2, 0}, {2, 1}},
		{{0, 1}, {1, 1}, {2, 0}, {2, 1}},
		{{0, 0}, {0, 1}, {1, 0}, {2, 0}},
		{{0, 0}, {0, 1}, {1, 1}, {2, 1}},
		{{0, 2}, {1, 0}, {1, 1}, {1, 2}},
		{{0, 0}, {1, 0}, {1, 1}, {1, 2}},
		{{0, 0}, {0, 1}, {0, 2}, {1, 2}},
		{{0, 0}, {0, 1}, {0, 2}, {1, 0}},
		{{0, 0}, {0, 1}, {1, 1}, {1, 2}},
		{{0, 1}, {1, 0}, {1, 1}, {2, 0}},
		{{0, 1}, {0, 2}, {1, 0}, {1, 1}},
		{{0, 0}, {1, 0}, {1, 1}, {2, 1}},
		{{0, 0}, {0, 1}, {0, 2}, {1, 1}},
		{{0, 1}, {1, 0}, {1, 1}, {2, 1}},
		{{0, 0}, {1, 0}, {1, 1}, {2, 0}},
		{{0, 1}, {1, 0}, {1, 1}, {1, 2}}
};
	return (copy_positions(g_strt_pos, piecenum));
}
