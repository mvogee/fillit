/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 21:35:41 by mvogee            #+#    #+#             */
/*   Updated: 2016/10/03 19:42:21 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef enum e_num
{
	SQUARE,
	LINE_VERT,
	LINE_HOR,
	L_VERT,
	BL_VERT,
	UL_VERT,
	UBL_VERT,
	L_HOR,
	LB_HOR,
	UL_HOR,
	UBL_HOR,
	Z_NORM,
	BZ_NORM,
	Z_HOR,
	BZ_HOR,
	T_NORM,
	T_UPSIDEDOWN,
	T_LEFT,
	T_RIGHT

}				e_nblocks;

void			read_file(char *file);

#endif
