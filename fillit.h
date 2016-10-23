/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 21:35:41 by mvogee            #+#    #+#             */
/*   Updated: 2016/10/05 15:20:51 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef enum			e_pieces
{
	NOT_SET = 			0,
	SQUARE = 			1,
	STRAT = 			2,
	STRAT_FLT = 		3,
	L = 				4,
	L_REVRS = 			5,
	L_INVRT = 			6,
	L_REVRS_INVRT = 	7,
	L_FLT = 			8,
	L_FLT_REVRS = 		9,
	L_FLT_INVRT = 		10,
	L_FLT_INVRT_REVRS = 11,
	Z = 				12,
	Z_ROTAT_REVRS = 	13,
	Z_REVRS = 			14,
	Z_ROTAT = 			15,
	T = 				16,
	T_ROTAT = 			17,
	T_ROTAT_REVRS = 	18,
	T_INVRT = 			19
}						t_type;

/* readv2 */
void			error_call(int type);
char			*open_file(char *file);
/* validation_check 1 and 2 */
int				*validation_check(char *pieces);
int				validate_file(char *pieces, int index);
int				hash_count(char *pieces);
/* valid_piece_compare */
int				valid_piece_compare(char *str);
/* piece_positions */
int				**get_positions(int piecenum);
/*  position_check */
int				find_xshift(int **positions);
int				**shift_positions(char **board, int **positions, int count, int count2);
int 			**check_positions(char **board, int **positions);
/* fillit */
char			**place_piece(char **board, int piecnum, int id);
int				start_solve(int *piecenums, char **board, int piececount, int count);
char			**create_board(int size, int colcount, int rowcount);
void			start_fillit(int *piecenums, int piececount);

#endif
