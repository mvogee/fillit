/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 10:20:10 by mvogee            #+#    #+#             */
/*   Updated: 2016/10/14 15:54:49 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* find_shift
** Takes the string and finds the number of dots it needs to be shifted
** in order to create a compareable string.
** Returns the number to shift to put the piece as far left as it can be.
** DONE WORKING
*/

static int		find_shift(char *str)
{
	int		shift;
	int		index;
	int		count;
	int		hashcount;

	index = 0;
	shift = 3;
	hashcount = 0;
	while (str[index])
	{
		if (str[index] == '\n' || index == 0)
			count = 0;
		if (str[index] != '\n' && str[index] != '#')
			count++;
		if (str[index] == '#')
		{
			hashcount++;
			if (count < shift)
				shift = count;
			if (hashcount == 4 || shift == 0)
				return (shift);
		}
		index++;
	}
	return (shift);
}

/* getlen
** Used in validate pieces
** Gets the length of the string we will need to
** create by counting how many indexes are btween
** the first hashtag and tha 4th
** DONE WORKING
*/

static int		getlen(char *str)
{
	int		counthash;
	int		len;
	int		index;

	counthash = 0;
	index = 0;
	len = 0;
	while (counthash < 4)
	{
		if (str[index] == '#')
			counthash++;
		len++;
		index++;
	}
	return (len);
}

/* copy_string
** used in validate_pieces to create the string to be compared against
** DONE WORKING
*/

static void		copy_string(char *str, char *piece, int len, int shift)
{
	int		index;
	int		count;

	index = 0;
	while (index < len)
	{
		if (*str != '\n')
			piece[index++] = *str++;
		else
		{
			count = 0;
			while (count < shift)
			{
				piece[index] = '.';
				index++;
				count++;
				str++;
			}
			piece[index] = '\n';
			str++;
			index++;
		}
	}
}

/* validate_pieces
** First count through and make sure each peice has exactly 4 hashtags.
** while doing so count how many pieces there are total.
**
** Create a funtion that takes the first
** index of a piece gird and creates a 2d array out of it.
** When we find the first # that we can start from
** that possition to make sure all 4 # connect.
**
** Retruns 0 if file has invalid pieces otherwise
** returns the ENUM of the identified piece.
** DONE WORKING
*/

static int		validate_pieces(char *str)
{
	int		len;
	char	*piece;
	int		shift;
	int		piecetype;

	shift = find_shift(str);
	while (*str != '#')
		str++;
	len = getlen(str);
	piece = (char*)malloc(sizeof(char) * len + 1);
	if (!piece)
		error_call(3);
	copy_string(str, piece, len, shift);
	piece[len] = '\0';
	piecetype = valid_piece_compare(piece);
	free(piece);
	return (piecetype);
}

/*
** this is the kickoff function. it calls all the validation functions
** aquires the number of given pieces from the validate_pieces function.
** makes sure we have 26 or less pieces.
** DONE WORKING
*/

int				*validation_check(char *pieces)
{
	int		piece_count;
	int		count;
	int		*pieces_array;

	count = 0;
	piece_count = validate_file(pieces, 0);
	if (piece_count == 0)
		error_call(2);
	piece_count = hash_count(pieces);
	if (piece_count == 0 || piece_count > 26)
		error_call(2);
	pieces_array = (int*)malloc(sizeof(int) * piece_count + 1);
	if (!pieces_array)
		error_call(3);
	while (count < piece_count)
	{
		pieces_array[count] = (validate_pieces(pieces));
		pieces += 21;
		count++;
	}
	pieces_array[count] = 0;
	return (pieces_array);
}
