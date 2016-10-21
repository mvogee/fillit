/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_piece_compare.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 10:34:22 by mvogee            #+#    #+#             */
/*   Updated: 2016/10/13 11:51:46 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_piece_compare_p2(char *str)
{
	if (ft_strcmp(str, "##..\n#...\n#") == 0)
		return (L_INVRT);
	if (ft_strcmp(str, "###.\n..#") == 0)
		return (L_FLT_INVRT);
	if (ft_strcmp(str, "##.\n##") == 0)
		return (Z_REVRS);
	if (ft_strcmp(str, "##..\n.##") == 0)
		return (Z);
	if (ft_strcmp(str, "#...\n##..\n.#") == 0)
		return (Z_ROTAT_REVRS);
	if (ft_strcmp(str, "#..\n##..\n#") == 0)
		return (Z_ROTAT);
	if (ft_strcmp(str, "#..\n###") == 0)
		return (T_INVRT);
	if (ft_strcmp(str, "#...\n##..\n#") == 0)
		return (T_ROTAT_REVRS);
	if (ft_strcmp(str, "#..\n##..\n.#") == 0)
		return (T_ROTAT);
	if (ft_strcmp(str, "###.\n.#") == 0)
		return (T);
	else
		error_call(2);
	return (0);
}

int		valid_piece_compare(char *str)
{
	if (ft_strcmp(str, "##..\n##") == 0)
		return (SQUARE);
	if (ft_strcmp(str, "#...\n#...\n#...\n#") == 0)
		return (STRAT);
	if (ft_strcmp(str, "####") == 0)
		return (STRAT_FLT);
	if (ft_strcmp(str, "#...\n#...\n##") == 0)
		return (L);
	if (ft_strcmp(str, "#.\n###") == 0)
		return (L_FLT);
	if (ft_strcmp(str, "##..\n.#..\n.#") == 0)
		return (L_REVRS_INVRT);
	if (ft_strcmp(str, "###.\n#") == 0)
		return (L_FLT_INVRT_REVRS);
	if (ft_strcmp(str, "#..\n.#..\n##") == 0)
		return (L_REVRS);
	if (ft_strcmp(str, "#...\n###") == 0)
		return (L_FLT_REVRS);
	else
		return (valid_piece_compare_p2(str));
}
