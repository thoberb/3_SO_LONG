/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:23:15 by bberthod          #+#    #+#             */
/*   Updated: 2023/02/17 13:48:24 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_parsing(t_game *game, char **argv)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return (0);
	game->map->check_letters.letter_c = 0;
	game->map->check_letters.letter_e = 0;
	game->map->check_letters.letter_p = 0;
	game->map->map_build = NULL;
	game->map->map_org = NULL;
	game->map->map_chck = NULL;
	if (ft_check_ext(argv[1]) == FAIL)
		return (ft_free_parsing(game, "wrong filename extension\n"), FAIL);
	if (ft_read_file(game, argv[1]) == FAIL)
		return (FAIL);
	if (ft_check_rectangular(game) == FAIL)
		return (FAIL);
	if (ft_nbr_letters(game) == FAIL)
		return (FAIL);
	if (ft_if_wall(game) == FAIL)
		return (ft_free_parsing(game, "there are some leaks on walls\n"), FAIL);
	if (ft_wrong_letters(game) == FAIL)
		return (ft_free_parsing(game,
				"Letters allowed on your map : P, C, E, 0, 1\n"), FAIL);
	if (ft_valid_path(game) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

int	ft_create_game(t_game *game)
{
	ft_display_map(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_putstr_fd("Error\nyou must call one arg\n", 2), 1);
	if (ft_parsing(&game, argv) == FAIL)
		return (1);
	ft_create_game(&game);
	return (0);
}
