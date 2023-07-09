/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:23:06 by jlozano-          #+#    #+#             */
/*   Updated: 2023/07/07 10:54:17 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

t_map	*create_map(int fd)
{
	int		i;
	char	*tab[100];
	char	*line;
	t_map	*map;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	tab[0] = line;
	line = get_next_line(fd);
	i = 1;
	while (line)
	{
		tab[i] = line;
		line = get_next_line(fd);
		++i;
	}
	tab[i] = NULL;
	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->size.y = i;
	map->size.x = -1;
	map->tab = tab;
	return (map);
}

int	sprites_create()

int	create_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (-1);
	game->win = mlx_new_window(game->mlx, game->map->size.x +200, game->map->size.y +200, "so_long");
	if (!game->win)
	{
		return (-1);
	}
	game->sprite =	sprites_create (game->mlx);
	return (0);
}

int	create_game(t_game *game, int fd)
{
	int	ret;

	game->map = create_map(fd);
	if (game->map == NULL)
	{
		return (-1);
	}
//	ret = validate_map(game->map);
	
	ret = create_window(game);
	return (0);
}

int	init_game(t_game *game, int fd)
{
	int ret;
	
	ft_bzero(game, sizeof(t_game));
	ret = create_game(game, fd);
	
	return (0);
}