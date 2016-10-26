/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 11:34:59 by mvogee            #+#    #+#             */
/*   Updated: 2016/10/13 14:07:54 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_pieces(int *array)
{
	int count;

	count = 0;
	while (array[count] != 0)
		count++;
	return (count);
}

int		main(int ac, char **av)
{
	char	*pieces_array;
	int		*pieces;

	if (ac == 2)
	{
		pieces_array = open_file(av[1]);
		pieces = validation_check(pieces_array);
		start_fillit(pieces, count_pieces(pieces));
	}
	else
		write(1, "usage: fillit input_file", 24);
	return (0);
}
