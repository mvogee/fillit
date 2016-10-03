/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 14:36:00 by mvogee            #+#    #+#             */
/*   Updated: 2016/10/02 22:43:52 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int main(int av, char **ac)
{
	if (av == 2)
	{
		printf("%s\n", ac[1]);
	}
	else
		write(1, "usage: ./fillit source_file", 27);
	int num;

	num = 1879;
	printf("\n%i\n", BUFF);
	if (num & 1)
		printf("odd");
	else
		printf("even");
	return (0);
}
