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

int		**get_positions(int id)
{
/*
	if (id == SQUARE)
		ret = { 0,0 , 0,1 , 1,0 , 1,1 };
	if (id == STRAT)
		ret = { 0,0 , 1,0 , 2,0, 3,0};
	if (id == STRAT_FLT)
		ret = { 0,0 , 0,1 , 0,2 , 0,3 };
	if (id == L)
		ret = { 0,0 , 1,0 , 2,0 , 2,1 };
	if (id == L_REVRS)
		ret = { 0,1 , 1,1 , 2,1 , 2,0 };
	if (id == L_INVRT)
		ret = { 0,1 , 0,0 , 1,0 , 2,0 };
	if (id == L_REVRS_INVRT)
		ret = { 0,0 , 0,1 , 1,1 , 2,1 };
	if (id == L_FLT)
		ret = { 0,2 , 1,2 , 1,1 , 1,0 };
	if (id == L_FLT_REVRS)
		ret = {  0,0 , 1,0 , 1,1 , 1,2 };
	if (id == L_FLT_INVRT)
		ret = { 1,2 , 0,2 , 0,1 , 0,0 };
	if (id == L_FLT_INVRT_REVRS)
		ret = { 1,0 , 0,0 , 0,1 , 0,2 };
	if (id == Z)
		ret = { 0,0 , 0,1 , 1,1 , 1,2 };
	if (id == Z_ROTAT_REVRS)
		ret = { 0,0 , 1,0 , 1,1 , 2,1 };
	if (id == Z_REVRS)
		ret = { 1,0 , 1,1 , 0,1 , 0,2 };
	if (id == Z_ROTAT)
		ret = { 0,1 , 1,1 , 1,0 , 2,0 };
	if (id == T)
		ret = { 0,0 , 0,1 , 1,1 , 0,2 };
	if (id == T_ROTAT)
		ret = { 0,1 , 1,1 , 1,0 , 2,1 };
	if (id == T_ROTAT_REVRS)
		ret = { 0,0 , 1,0 , 1,1 , 2,0 };
	else //(id == T_INVRT)
		ret = { 0,1 , 1,0 , 1,1 , 1,2 };
*/
	/*
** starting coordinates of each piece placed nearest to the upper left corner of
** the board.
*/

/*
** each index i in g_strt_pos[i] represents one of the 19 possible tetraminos
** each index j in g_strt_pos[i][j] represents a row and column location of a
** square in the tetramino piece
*/

int							g_strt_pos[20][4][2] = {
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
	return (g_strt_pos[id]);
}

int main(void)
{
	int ptr[4][2];
	ptr = get_positions(1);
	return (0);
}