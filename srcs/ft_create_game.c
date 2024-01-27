/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:23:42 by bberthod          #+#    #+#             */
/*   Updated: 2023/03/03 18:49:13 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_put_images_to_win(t_game *game, int *ite_row, int *ite_col)
{
	if (game->map->map_org[(*ite_row)][(*ite_col)] == '0')
		mlx_put_image_to_window((game->mlibx), (game->window),
			game->img_0, (*ite_col) * 150, (*ite_row) * 150);
	else if (game->map->map_org[(*ite_row)][(*ite_col)] == '1')
		mlx_put_image_to_window((game->mlibx), (game->window),
			game->img_1, (*ite_col) * 150, (*ite_row) * 150);
	else if (game->map->map_org[(*ite_row)][(*ite_col)] == 'E')
		mlx_put_image_to_window((game->mlibx), (game->window),
			game->img_e, (*ite_col) * 150, (*ite_row) * 150);
	else if (game->map->map_org[(*ite_row)][(*ite_col)] == 'C')
		mlx_put_image_to_window((game->mlibx), (game->window),
			game->img_c, (*ite_col) * 150, (*ite_row) * 150);
	else if (game->map->map_org[(*ite_row)][(*ite_col)] == 'P')
		mlx_put_image_to_window((game->mlibx), (game->window),
			game->img_p, (*ite_col) * 150, (*ite_row) * 150);
	else if (game->map->map_org[(*ite_row)][(*ite_col)] == 'M')
		mlx_put_image_to_window((game->mlibx), (game->window),
			game->img_m, (*ite_col) * 150, (*ite_row) * 150);
}

void	ft_init_sprite(t_game *game)
{
	ft_init_img(game);
	game->img_0 = mlx_xpm_file_to_image(game->mlibx,
			"./img/BGtile.xpm", &game->img_size, &game->img_size);
	if (game->img_0 == NULL)
		ft_destroy_and_free(game, "Error\nSomething wrong happened with img\n");
	game->img_1 = mlx_xpm_file_to_image(game->mlibx,
			"./img/tile.xpm", &game->img_size, &game->img_size);
	if (game->img_1 == NULL)
		ft_destroy_and_free(game, "Error\nSomething wrong happened with img\n");
	game->img_p = mlx_xpm_file_to_image(game->mlibx,
			"./img/perso.xpm", &game->img_size, &game->img_size);
	if (game->img_p == NULL)
		ft_destroy_and_free(game, "Error\nSomething wrong happened with img\n");
	game->img_c = mlx_xpm_file_to_image(game->mlibx,
			"./img/coeur.xpm", &game->img_size, &game->img_size);
	if (game->img_c == NULL)
		ft_destroy_and_free(game, "Error\nSomething wrong happened with img\n");
	game->img_e = mlx_xpm_file_to_image(game->mlibx,
			"./img/porteopen.xpm", &game->img_size, &game->img_size);
	if (game->img_e == NULL)
		ft_destroy_and_free(game, "Error\nSomething wrong happened with img\n");
	game->img_m = mlx_xpm_file_to_image(game->mlibx,
			"./img/mechant.xpm", &game->img_size, &game->img_size);
	if (game->img_e == NULL)
		ft_destroy_and_free(game, "Error\nSomething wrong happened with img\n");
}

void	ft_place_tiles(t_game *game)
{
	int	ite_row;
	int	ite_col;

	ite_row = 0;
	ite_col = 0;
	while (game->map->map_org[ite_row])
	{
		ite_col = 0;
		while (game->map->map_org[ite_row][ite_col])
		{
			ft_put_images_to_win(game, &ite_row, &ite_col);
			ite_col++;
		}
		ite_row++;
	}
	ft_put_count(game);
}

int	ft_event_listen(int key, t_game *game)
{
	if (key == 65307)
		ft_destroy_and_free(game, NULL);
	if (key == XK_w)
	{
		ft_move_w(game);
		ft_place_tiles(game);
	}
	else if (key == XK_s)
	{
		ft_move_s(game);
		ft_place_tiles(game);
	}
	else if (key == XK_a)
	{
		ft_move_a(game);
		ft_place_tiles(game);
	}
	else if (key == XK_d)
	{
		ft_move_d(game);
		ft_place_tiles(game);
	}
	return (0);
}

int	ft_display_map(t_game *game)
{
	(game->img_size) = 150;
	(game->mlibx) = mlx_init();
	if (game->mlibx == NULL)
		return (ft_free_parsing(game, "environnement NULL\n"), FAIL);
	game->window = mlx_new_window((game->mlibx),
			game->map->w * 150, game->map->h * 150, "so_long");
	if (game->window == NULL)
		return (free(game->window), FAIL);
	game->map->count_step = 0;
	ft_init_sprite(game);
	ft_place_tiles(game);
	ft_find_p(game);
	ft_put_count(game);
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, \
	&ft_destroy_and_free, game);
	mlx_hook(game->window, KeyPress, KeyPressMask, &ft_event_listen, game);
	mlx_hook(game->window, 17, 1L << 2, ft_exit, game);
	mlx_loop(game->mlibx);
	ft_destroy_and_free(game, NULL);
	return (free(game->mlibx), SUCCESS);
}
