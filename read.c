/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfredric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 11:49:12 by cfredric          #+#    #+#             */
/*   Updated: 2016/10/03 20:04:53 by cfredric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		error_call(void)
{
	write(1, "error: invalid file\n", 20);
	exit(1);
}

static int		open_file(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_call();
	return (fd);
}

// static char 	**create_piece(char *buf)

static void		between_pieces(int fd)
{
	char	buf[1];
	int		check;

	check = read(fd, buf, 1);
	if (!check || buf[0] == '\n')
		error_call();
}

static int		fill_buf(int fd)
{
	char	buf[5];
	int		check;
	int		i;
	int		block_count;

	// read might return less than 5 and be ok
	check = read(fd, buf, 20);
	if (!check)
		return (0);
	if (check != 20)
		error_call();
	i = 0;
	block_count = 0;
	while (i < 20)
	{
		if (i % 4 == 0 && buf[i++] != '\n')
			error_call();
		if (buf[i] != '.' || buf[i] != '#')
			error_call();
		if (buf[i] == '#')
			block_count++;
		if (block_count > 4)
			error_call();
		i++;
	}
	return (1);
}

static void		between_piece(int fd)
{
	char	buf[1];
	int		check;

	check = read(fd, buf, 1);
	if (!check || buf[0] == '\n')
		error_call();
}

// char 	**create_piece(char *buf)

void			read_file(char *file)
{
	unsigned int	piece_count;
	unsigned int	fd;

	fd = open_file(file);
	piece_count = 0;
	while (1)
	{
		if (!fill_buf(fd))
			break ;
		else
			piece_count++;
		if (piece_count > 26)
			error_call();
		between_pieces(fd);
	}
	if (close(fd) != 0)
		error_call();
}

