/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfredric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 11:49:12 by cfredric          #+#    #+#             */
/*   Updated: 2016/10/04 21:38:09 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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
	{
		printf("Occured on line %d.\n", __LINE__);
		error_call();
	}
	return (fd);
}

// static char 	**create_piece(char *buf)

/*
static void		between_pieces(int fd)
{
	char	buf[1];
	int		check;

	check = read(fd, buf, 1);
	if (!check || buf[0] == '\n')
	{
		printf("Occured on line %d.\n", __LINE__);
		error_call();
	}
}
*/

static int		fill_buf(int fd)
{
	char	buf[5];
	int		check;
	int		i;
	int		block_count;
	int		c_count;

	c_count = 0;
	// read might return less than 5 and be ok
	check = read(fd, buf, 20);
	printf("%s\n", buf);
	if (!check)
		return (0);
	if (check != 20)
	{
		printf("Occured on line %d.\n", __LINE__);
		error_call();
	}
	i = 0;
	block_count = 0;
	while (i < 19)
	{
		if (c_count % 4 == 0 && c_count >= 4 && buf[i++] != '\n')
		{
			printf("Occured on line %d, i = %d.\n", __LINE__, i);
			error_call();
			c_count = 0;
		}
		if (buf[i] != '.' && buf[i] != '#')
		{
			printf("Occured on line %d, i = %d, char = %c.\n", __LINE__, i, buf[i]);
			error_call();
		}
		if (buf[i] == '#')
			block_count++;
		if (block_count > 4)
		{
			printf("Occured on line %d.\n", __LINE__);
			error_call();
		}
		i++;
		c_count++;
	}
	return (1);
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
		{
			printf("IT WORKS MATT!!!\n");
			printf("piece_count = %d\n", piece_count);
			piece_count++;
			printf("piece_count = %d\n", piece_count);
		}
		if (piece_count > 26)
		{
			printf("Occured on line %d.\n", __LINE__);
			error_call();
		}
//		between_pieces(fd);
//		break ;
	}
	if (close(fd) != 0)
	{
		printf("Occured on line %d.\n", __LINE__);
		error_call();
	}
}

