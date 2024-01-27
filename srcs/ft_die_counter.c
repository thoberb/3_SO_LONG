/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die_counter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:40:05 by bberthod          #+#    #+#             */
/*   Updated: 2023/03/07 18:19:17 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_exit(t_game *game)
{
	write(1, "Vous avez quitte la partie !\n", 29);
	ft_destroy_and_free(game, NULL);
	return (0);
}

char	*ft_die_path(char *die_path, t_game *game)
{
	int	j;

	j = 0;
	die_path[j++] = '.';
	die_path[j++] = '/';
	die_path[j++] = 'i';
	die_path[j++] = 'm';
	die_path[j++] = 'g';
	die_path[j++] = '/';
	die_path[j++] = 'D';
	die_path[j++] = (char)('0' + (game->die / 10));
	die_path[j++] = (char)('0' + (game->die % 10));
	die_path[j++] = '.';
	die_path[j++] = 'x';
	die_path[j++] = 'p';
	die_path[j++] = 'm';
	die_path[j++] = '\0';
	return (die_path);
}

void	ft_die(t_game *game)
{
	int		width;
	int		height;
	char	*die_path;

	while (game->die <= 20)
	{
		die_path = malloc(sizeof(char) * 14);
		if (!die_path)
			ft_destroy_and_free(game, "Error\nmalloc error\n");
		die_path = ft_die_path(die_path, game);
		game->img_die = mlx_xpm_file_to_image(game->mlibx, die_path,
				&width, &height);
		mlx_put_image_to_window(game->mlibx, game->window, game->img_die,
			(game->map->p_x * 150), (game->map->p_y * 150));
		mlx_destroy_image(game->mlibx, game->img_die);
		free(die_path);
		game->die++;
	}
	ft_putstr_fd("GAME OVER, you're dead !\n", 1);
	ft_destroy_and_free(game, NULL);
}

char	*ft_number_path(char *number_path, t_game *game)
{
	int	j;

	j = 0;
	number_path[j++] = '.';
	number_path[j++] = '/';
	number_path[j++] = 'i';
	number_path[j++] = 'm';
	number_path[j++] = 'g';
	number_path[j++] = '/';
	number_path[j++] = (char)('0' + (game->map->count_step / 10));
	number_path[j++] = (char)('0' + (game->map->count_step % 10));
	number_path[j++] = '.';
	number_path[j++] = 'x';
	number_path[j++] = 'p';
	number_path[j++] = 'm';
	number_path[j++] = '\0';
	return (number_path);
}

void	ft_put_count(t_game *game)
{
	int		width;
	int		height;
	char	*number_path;
	char	*number_path99;

	number_path = malloc(sizeof(char) * 13);
	if (!number_path)
		ft_destroy_and_free(game, "Error\nmalloc error\n");
	if (game->map->count_step < 99)
	{
		number_path = ft_number_path(number_path, game);
		game->img_counter = mlx_xpm_file_to_image(game->mlibx, number_path,
				&width, &height);
	}
	else
	{
		number_path99 = "./img/99.xpm";
		game->img_counter = mlx_xpm_file_to_image(game->mlibx, number_path99,
				&width, &height);
	}
	mlx_put_image_to_window(game->mlibx, game->window,
		game->img_counter, 0, 0);
	mlx_destroy_image(game->mlibx, game->img_counter);
	free(number_path);
}
