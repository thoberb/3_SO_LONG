/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:22:20 by bberthod          #+#    #+#             */
/*   Updated: 2023/03/03 18:46:43 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_check_rectangular(t_game *game)
{
	int	ite_check1;
	int	prev;

	ite_check1 = 0;
	prev = ft_strlen(game->map->map_org[ite_check1]);
	while (game->map->map_org[++ite_check1])
	{
		if (prev != (int)ft_strlen(game->map->map_org[ite_check1]))
			return (ft_free_parsing(game, "map must be rectangular\n"), FAIL);
		prev = ft_strlen(game->map->map_org[ite_check1]);
	}
	game->map->h = ite_check1;
	game->map->w = prev;
	if (game->map->h > 9 || game->map->w > 17)
		return (ft_free_parsing(game, "map too big to play\n"), FAIL);
	return (SUCCESS);
}

int	ft_nbr_letters(t_game *game)
{
	int	ite_letter1;
	int	ite_letter2;

	ite_letter1 = -1;
	while (game->map->map_org[++ite_letter1])
	{
		ite_letter2 = -1;
		while (game->map->map_org[ite_letter1][++ite_letter2])
		{
			if (game->map->map_org[ite_letter1][ite_letter2] == 'C')
				game->map->check_letters.letter_c++;
			else if (game->map->map_org[ite_letter1][ite_letter2] == 'E')
				game->map->check_letters.letter_e++;
			else if (game->map->map_org[ite_letter1][ite_letter2] == 'P')
				game->map->check_letters.letter_p++;
		}
	}
	if (game->map->check_letters.letter_c == 0)
		return (ft_free_parsing(game,
				"your map must contain at least one C\n"), FAIL);
	if (game->map->check_letters.letter_e != 1)
		return (ft_free_parsing(game, "Your map must contain one E\n"), FAIL);
	if (game->map->check_letters.letter_p != 1)
		return (ft_free_parsing(game, "Your map must contain one P\n"), FAIL);
	return (SUCCESS);
}

int	ft_wrong_letters(t_game *game)
{
	int	ite_wrg_letter1;
	int	ite_wrg_letter2;

	ite_wrg_letter1 = -1;
	while (game->map->map_org[++ite_wrg_letter1])
	{
		ite_wrg_letter2 = -1;
		while (game->map->map_org[ite_wrg_letter1][++ite_wrg_letter2])
		{
			if (game->map->map_org[ite_wrg_letter1][ite_wrg_letter2] != 'C' &&
			game->map->map_org[ite_wrg_letter1][ite_wrg_letter2] != 'E' &&
			game->map->map_org[ite_wrg_letter1][ite_wrg_letter2] != 'P' &&
			game->map->map_org[ite_wrg_letter1][ite_wrg_letter2] != '0' &&
			game->map->map_org[ite_wrg_letter1][ite_wrg_letter2] != 'M' &&
			game->map->map_org[ite_wrg_letter1][ite_wrg_letter2] != '1')
				return (FAIL);
		}
	}
	return (SUCCESS);
}

int	ft_if_wall(t_game *game)
{
	int	ite_wall1;
	int	ite_wall2;

	ite_wall1 = -1;
	while (game->map->map_org[++ite_wall1])
	{
		ite_wall2 = -1;
		while (game->map->map_org[ite_wall1][++ite_wall2])
		{
			if ((ite_wall1 == 0 || ite_wall1 == game->map->h - 1)
				&& game->map->map_org[ite_wall1][ite_wall2] != '1')
				return (FAIL);
			if ((ite_wall2 == 0 || ite_wall2 == game->map->w - 1)
				&& game->map->map_org[ite_wall1][ite_wall2] != '1')
				return (FAIL);
		}
	}
	return (SUCCESS);
}
