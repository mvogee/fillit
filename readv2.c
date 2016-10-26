/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readv2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 11:00:14 by mvogee            #+#    #+#             */
/*   Updated: 2016/10/10 17:43:58 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* error_call
** displays error message and exits program with FAILURE
*/

void			error_call(int type)
{
	if (type == 1)
		write(1, "error: problem reading file\n", 28);
	if (type == 2)
		write(1, "error: invalid file\n", 20);
	if (type == 3)
		write(1, "error: allocation problem\n", 26);
	exit(EXIT_FAILURE);
}

/* get_fd
** opens file and returns file descirptor
*/

static int		get_fd(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_call(1);
	return (fd);
}

/*
**	read_file reads the given file descriptor and returns an array
**	created from the file to validation checking function.
*/

static char		*read_file(int fd)
{
	char	buf[546];
	char	*pieces_array;
	int		bytes_read;

	bytes_read = read(fd, buf, 546);
	if (bytes_read <= 0)
		error_call(3);
	pieces_array = (char*)ft_memalloc(bytes_read + 1);
	if (!(pieces_array))
		error_call(3);
	pieces_array = ft_strncpy(pieces_array, buf, bytes_read + 1);
	return (pieces_array);
}

/*
** kickoff funciton
** passes pieces_array to validation check.
*/

char			*open_file(char *file)
{
	int		fd;
	char	*pieces_array;

	fd = get_fd(file);
	pieces_array = read_file(fd);
	return (pieces_array);
}
