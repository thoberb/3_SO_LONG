/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:23:08 by bberthod          #+#    #+#             */
/*   Updated: 2023/03/03 18:51:05 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_check_exit(t_game *game)
{
	int	ite_collect1;
	int	ite_collect2;

	ite_collect1 = -1;
	while (game->map->map_org[++ite_collect1])
	{
		ite_collect2 = -1;
		while (game->map->map_org[ite_collect1][++ite_collect2])
		{
			if (game->map->map_org[ite_collect1][ite_collect2] == 'C')
				return (FAIL);
		}
	}
	return (SUCCESS);
}

void	ft_move_w(t_game *game)
{
	if (game->map->map_org[game->map->p_y - 1][game->map->p_x] == '0' ||
		game->map->map_org[game->map->p_y - 1][game->map->p_x] == 'C')
	{
		ft_find_p(game);
		ft_remove_p(game);
		ft_place_p(game, game->map->p_y - 1, game->map->p_x);
		if (game->img_p == NULL)
			ft_destroy_and_free(game, "Error\nproblem with image...\n");
		game->map->count_step++;
		ft_printf("step: %i\n", game->map->count_step);
	}
	else if (game->map->map_org[game->map->p_y - 1][game->map->p_x] == 'E')
	{
		if (ft_check_exit(game) == SUCCESS)
		{
			game->map->count_step++;
			ft_printf("step: %i\n", game->map->count_step);
			ft_putstr_fd("You won :)\n", 1);
			ft_destroy_and_free(game, NULL);
		}
	}
	else if (game->map->map_org[game->map->p_y - 1][game->map->p_x] == 'M')
		ft_die(game);
}

void	ft_move_s(t_game *game)
{
	if (game->map->map_org[game->map->p_y + 1][game->map->p_x] == '0' ||
		game->map->map_org[game->map->p_y + 1][game->map->p_x] == 'C')
	{
		ft_find_p(game);
		ft_remove_p(game);
		ft_place_p(game, game->map->p_y + 1, game->map->p_x);
		if (game->img_p == NULL)
			ft_destroy_and_free(game, "Error\nproblem with image...\n");
		game->map->count_step++;
		ft_printf("step: %i\n", game->map->count_step);
	}
	else if (game->map->map_org[game->map->p_y + 1][game->map->p_x] == 'E')
	{
		if (ft_check_exit(game) == SUCCESS)
		{
			game->map->count_step++;
			ft_printf("step: %i\n", game->map->count_step);
			ft_putstr_fd("You won :)\n", 1);
			ft_destroy_and_free(game, NULL);
		}
	}
	else if (game->map->map_org[game->map->p_y + 1][game->map->p_x] == 'M')
		ft_die(game);
}

void	ft_move_a(t_game *game)
{
	if (game->map->map_org[game->map->p_y][game->map->p_x - 1] == '0' ||
		game->map->map_org[game->map->p_y][game->map->p_x - 1] == 'C')
	{
		ft_find_p(game);
		ft_remove_p(game);
		ft_place_p(game, game->map->p_y, game->map->p_x - 1);
		if (game->img_p == NULL)
			ft_destroy_and_free(game, "Error\nproblem with image...\n");
		game->map->count_step++;
		ft_printf("step: %i\n", game->map->count_step);
	}
	else if (game->map->map_org[game->map->p_y][game->map->p_x - 1] == 'E')
	{
		if (ft_check_exit(game) == SUCCESS)
		{
			game->map->count_step++;
			ft_printf("step: %i\n", game->map->count_step);
			ft_putstr_fd("You won :)\n", 1);
			ft_destroy_and_free(game, NULL);
		}
	}
	else if (game->map->map_org[game->map->p_y][game->map->p_x - 1] == 'M')
		ft_die(game);
}

void	ft_move_d(t_game *game)
{
	if (game->map->map_org[game->map->p_y][game->map->p_x + 1] == '0' ||
		game->map->map_org[game->map->p_y][game->map->p_x + 1] == 'C')
	{
		ft_find_p(game);
		ft_remove_p(game);
		ft_place_p(game, game->map->p_y, game->map->p_x + 1);
		if (game->img_p == NULL)
			ft_destroy_and_free(game, "Error\nproblem with image...\n");
		game->map->count_step++;
		ft_printf("step: %i\n", game->map->count_step);
	}
	else if (game->map->map_org[game->map->p_y][game->map->p_x + 1] == 'E')
	{
		if (ft_check_exit(game) == SUCCESS)
		{
			game->map->count_step++;
			ft_printf("step: %i\n", game->map->count_step);
			ft_putstr_fd("You won :)\n", 1);
			ft_destroy_and_free(game, NULL);
		}
	}
	else if (game->map->map_org[game->map->p_y][game->map->p_x + 1] == 'M')
		ft_die(game);
}
