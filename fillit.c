/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 14:36:00 by mvogee            #+#    #+#             */
/*   Updated: 2016/10/03 20:55:38 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int main(int ac, char **av)
{
	int		fd;
	size_t	buf;
	char	*tmp;
	char	*fullstr;
	size_t	fullsize;

	buf = 1;
	fullsize = 0;

	if (ac == 2)
	{
		while
		{
			fd = open(av[1], O_RDONLY);
			tmp = (char*)malloc(sizeof(char) * buf + 1);
			(void)read(fd, tmp, buf);
			fullsize++;
			fullstr = (char*)malloc
		}
	}
	else 
		printf("you are stupid");
	return (0);
}
