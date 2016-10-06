/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readv2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 11:00:14 by mvogee            #+#    #+#             */
/*   Updated: 2016/10/05 18:55:15 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		error_call(void)
{
	write(1, "error: invalid file\n", 20);
	exit(42);
}

static int	get_fd(char *file)
{
	write(1, "entered get_fd\n", 18);			//remove this line
	int 	fd;

	fd = open(file, O_RDONLY); 
	if (fd == -1)
		error_call();
	return (fd);
}

char		*create_array(char *str, char newchar)
{
	write(1, "entered create_array\n", 21); 	//remove this line
	char	*tmp;
	int		len;

	len = (int)ft_strlen(str);
	printf("got len: %i\n", len);			//remove this line
	tmp = (char*)malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	tmp = ft_strcpy(tmp, str);
	free(str);
	write(1, "str copied to tmp\n",18);		//remove this line
	str = (char*)malloc(sizeof(char) * len + 2);
	if (!str)
		return (NULL);
	str = ft_strcpy(str, tmp);
	write(1, "tmp copied back to str\n", 23);	//remove this line
	free(tmp);
	str = ft_strcat(str, &newchar);
	printf("%s\n", str); 						// remove this line
	return (str);
}

void		read_file(int fd)
{
	write(1, "entered read_file\n", 18); 		// remove this line
	char	buf[1];
	char	*pieces_array;
	int		bytes_read;
	
	pieces_array = "\0";
	bytes_read = read(fd, buf, 1);
	while (bytes_read > 0)
	{
		write(1, &buf, 1); 						// remove this line
		pieces_array = create_array(pieces_array, *buf);
		if (!pieces_array)
			error_call();
		bytes_read = read(fd, buf, 1);
	}
}

void		open_file(char *file)
{
	write(1, "entered open_file\n", 18); 		// remove this line
	int fd;

	fd = get_fd(file);
	write(1, "got fd\n", 7); 					// remove this line
	read_file(fd);	
}
