/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_filemap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:22:10 by bberthod          #+#    #+#             */
/*   Updated: 2023/03/03 18:46:14 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_buf_read(int fd, t_game *game)
{
	char	buf[2];
	int		ret;

	buf[0] = 'X';
	buf[1] = '\0';
	if (fd < 0 || fd > 1024 || read(fd, 0, 0) < 0)
		return (ft_free_parsing(game, "Something wrong with args\n"), FAIL);
	while (buf[0] != '\0')
	{
		ret = read(fd, buf, 1);
		if (ret < 0)
			return (ft_free_parsing(game, "Something wrong with args\n"), FAIL);
		buf[ret] = '\0';
		buf[1] = '\0';
		if (!game->map->map_build)
			game->map->map_build = ft_strdup(buf);
		else
			game->map->map_build = ft_strjoin(game->map->map_build, buf);
	}
	if (ft_check_map(game->map->map_build, game) == FAIL)
		return (FAIL);
	game->map->map_org = ft_split(game->map->map_build, '\n');
	game->map->map_chck = ft_split(game->map->map_build, '\n');
	return (free(game->map->map_build), game->map->map_build = NULL, SUCCESS);
}

int	ft_is_letter(char chr)
{
	if (chr == 'C' || chr == 'E' || chr == 'P'
		|| chr == '0' || chr == '1' || chr == 'M')
		return (SUCCESS);
	return (FAIL);
}

int	ft_check_map(char *str, t_game *game)
{
	int	ite_back;
	int	count;

	count = 0;
	ite_back = 0;
	if (str[ite_back] == '\0')
		return (ft_free_parsing(game,
				"map empty\n"), FAIL);
	while (str[ite_back + 1])
	{
		if (str[ite_back] == '\n' && str[ite_back + 1] == '\n')
			count++;
		if (count > 0 && ft_is_letter(str[ite_back]) == SUCCESS)
			return (ft_free_parsing(game,
					"a file must contain one map\n"), FAIL);
		ite_back++;
	}
	return (SUCCESS);
}

int	ft_read_file(t_game *game, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_free_parsing(game, "The file does not exist\n"), FAIL);
	if (ft_buf_read(fd, game) == FAIL)
		return (FAIL);
	if (close(fd) == -1)
		return (ft_free_parsing(game, "Close error\n"), FAIL);
	return (SUCCESS);
}

int	ft_check_ext(char *filename)
{
	int	len;

	len = (ft_strlen(filename) - 1);
	if (filename[len] == 'r'
		&& filename[len - 1] == 'e'
		&& filename[len - 2] == 'b'
		&& filename[len - 3] == '.')
		return (SUCCESS);
	return (FAIL);
}
