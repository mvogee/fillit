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

int		get_size(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\n' && str[count] != '\0')
		count++;
	return (count);
}

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
	write(1, "	BOARD FREEEE\n\n", 15);
}

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
		while(board[count][count2] != '\0')
		{
			write(1, &board[count][count2], 1);
			count2++;
		}
		count++;
		count2 = 0;
	}
	write(1, "\n", 1);
}
