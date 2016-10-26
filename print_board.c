/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:29:36 by mvogee            #+#    #+#             */
/*   Updated: 2016/10/24 15:29:39 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** get_size
** finds the size of the board by finding the lenfth of one line
** RETURN: size of the board
*/

int		get_size(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\n' && str[count] != '\0')
		count++;
	return (count);
}

/*
** free_board
** frees all memory allocated for the board
*/

void	free_board(char **board)
{
	int size;
	int count;

	size = get_size(board[0]);
	count = 0;
	if (!board)
		return ;
	while (count < size)
	{
		free(board[count]);
		count++;
	}
}

/*
** print_board
** prints the board! who would have guessed!?
*/

void	print_board(char **board)
{
	int count;
	int count2;
	int size;

	count = 0;
	count2 = 0;
	size = get_size(board[0]);
	while (count < size)
	{
		while (board[count][count2] != '\0')
		{
			write(1, &board[count][count2], 1);
			count2++;
		}
		count++;
		count2 = 0;
	}
	write(1, "\n", 1);
}
