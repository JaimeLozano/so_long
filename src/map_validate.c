/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 08:54:07 by jaime             #+#    #+#             */
/*   Updated: 2023/09/08 17:44:56 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "game.h"
#include "libft.h"

static void	player_setpos(t_player *player, t_point point)
{
	player->pos.x = point.x;
	player->pos.y = point.y;
}

static void	check_items(t_map *map, t_player *player)
{
	t_point		point;
	char		*pos;

	point.x = map->size.x;
	point.y = map->size.y;
	while (point.y--)
	{
		while (point.x--)
		{
			pos = &map->buffer[point.y][point.x];
			if (*pos == EXIT_CHAR)
				map->exit_present++;
			else if (*pos == COIN_CHAR)
				map->coins++;
			else if (*pos == PLAYER_CHAR)
			{
				map->player_present++;
				*pos = FLOOR_CHAR;
				player_setpos(player, point);
			}
			else if (*pos != WALL_CHAR && *pos != FLOOR_CHAR)
				map->exit_present = INT32_MAX;
		}
		point.x = map->size.x;
	}
}

static int	dfs(int row, int col, int **visited, t_game *game)
{
	if (row < 0 || row >= game->map->size.y || col < 0 || \
								col >= game->map->size.x)
		return (0);
	if (visited[row][col])
		return (0);
	visited[row][col] = 1;
	if (game->map->buffer[row][col] == 'E')
		return (1);
	if (game->map->buffer[row][col] == '0' || \
		game->map->buffer[row][col] == 'C' || \
		game->map->buffer[row][col] == 'P')
	{
		if (dfs(row - 1, col, visited, game) || \
			dfs(row + 1, col, visited, game) || \
			dfs(row, col - 1, visited, game) || \
			dfs(row, col + 1, visited, game))
			return (1);
	}
	return (0);
}

static void	check_path(t_game *game)
{
	int	i;
	int	**visited;
	int	path_exist;

	i = 0;
	visited = (int **)ft_calloc(game->map->size.y, sizeof(int *));
	while (i < game->map->size.y)
	{
		visited[i] = ft_calloc(game->map->size.x, sizeof(int));
		i++;
	}
	path_exist = dfs(game->player.pos.y, game->player.pos.x, visited, game);
	i = 0;
	while (i < game->map->size.y)
	{
		free(visited[i]);
		visited[i] = NULL;
		i++;
	}
	free(visited);
	if (!path_exist)
	{
		map_free(game->map);
		print_error(ERROR_PATH);
	}
}

void	map_validate(t_game *game)
{
	t_map	*map;

	map = game->map;
	game->player.move_counter = 0;
	check_corners(map);
	check_items(game->map, &game->player);
	if (map->exit_present != 1 || map->player_present != 1 || map->coins < 1)
	{
		map_free(map);
		print_error(ERROR_ITEMS);
	}
	check_path(game);
}
