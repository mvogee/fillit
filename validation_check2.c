/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_check2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 11:39:51 by mvogee            #+#    #+#             */
/*   Updated: 2016/10/17 11:39:53 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** validate_file
** this funciton makes sure the file doesnt contain any incorrect characters or
** is missing any characters and that te the maps are the correct size.
** only thing left to check after this is that pieces are correct.
** (index is hard code passed as a parameter only to save lines)
** DONE WORKING
*/

int		validate_file(char *pieces, int index)
{
	int		line;
	int		chars;

	line = 0;
	chars = 0;
	while (pieces[index])
	{
		chars++;
		if (pieces[index] != '#' && pieces[index] != '.' &&
			pieces[index] != '\n')
			return (0);
		if (pieces[index] == '\n')
		{
			line++;
			if (chars != 5 && line != 5)
				return (0);
			chars = 0;
		}
		if (line == 5 && pieces[index])
			line = 0;
		index++;
	}
	if (line != 4)
		return (0);
	return (1);
}

/*
** hash_count
** parameter takes in entire array of pieces
** Count how many hashtags there are. return 0 if there is not 4 hash marks
** in a piece. otherwise retrun the number of pieces.
** DONE WORKING
*/

int		hash_count(char *pieces)
{
	int		index;
	int		hash;
	int		totalpieces;
	int		line;

	index = 0;
	hash = 0;
	totalpieces = 0;
	line = 1;
	while (pieces[index])
	{
		if (pieces[index] == '#')
			hash++;
		if (pieces[index] == '\n')
			line++;
		if (line % 5 == 0 && hash % 4 == 0)
			totalpieces++;
		else if (line % 5 == 0 && hash % 4 != 0)
			return (0);
		index++;
	}
	if (hash % 4 != 0)
		return (0);
	return (totalpieces);
}
