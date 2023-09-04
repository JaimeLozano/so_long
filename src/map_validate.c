/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaime <jaime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 08:54:07 by jaime             #+#    #+#             */
/*   Updated: 2023/09/02 17:37:09 by jaime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "game.h"
#include "libft.h"

static void	validateItems(t_game *game)
{
	int	i;
	int	j;
	char *pos;
	t_map	*map;
	t_player	*player;

	map = game->map;
	player = game->player;
	j = map->size.x;
	i = map->size.y;
	while (i--)
	{
		while (j--)
		{
			pos = &map->buffer[i][j];
			if (*pos == EXIT_CHAR)
				map->exit_present++;
			else if (*pos == COIN_CHAR)
    			map->coins++;
			else if (*pos == PLAYER_CHAR)
			{
				map->player_present++;
				*pos = FLOOR_CHAR;
				player->pos.x = j;
				player->pos.y = i;
			}
			else if (*pos != WALL_CHAR && *pos != FLOOR_CHAR)
				map->exit_present = -100;
		}
		j = map->size.x;
	}
}

static void	checkTopLine(t_map *map, int i)
{
	int	j;

	j = 0;
	while (map->buffer[i][j] == WALL_CHAR)
		j++;
	if (map->size.x != j)
	{
		map_free(map);
		print_error(ERROR_TOP);
	}
}

static void	checkBodyLine(t_map *map, int i)
{
	int ret;

	ret = 0;
	if (map->buffer[i][0] != WALL_CHAR)
		ret = 1;
	if (map->buffer[i][map->size.x  - 1] != WALL_CHAR)
		ret = 2;
	if ((int)ft_strlen(map->buffer[i]) - 1 != map->size.x)
		ret = 3;
	if (ret != 0)
	{
		map_free(map);
		print_error(ERROR_BODY);
	}
}

static void	checkBottomLine(t_map *map, int i)
{
	int	j;

	j = 0;
	while (map->buffer[i][j] == WALL_CHAR)
		j++;
	if (map->size.x != j)
	{
		map_free(map);
		print_error(ERROR_BOTTOM);
	}
}

static void	validateCorners(t_map *map)
{
	int	i;

	i = 0;
	checkTopLine(map, i++);
	while (i < (map->size.y - 1))
		checkBodyLine(map, i++);
	checkBottomLine(map, i);
}

static int	dfs(int	row, int	col, int	**visited, t_game *game)
{
	if (row < 0 || row >= game->map->size.y || col < 0 || col >= game->map->size.x)
        return 0;
    if (visited[row][col])
        return 0;
    visited[row][col] = 1;
    if (game->map->buffer[row][col] == 'E')
        return 1;
    if (game->map->buffer[row][col] == '0' || game->map->buffer[row][col] == 'C' || game->map->buffer[row][col] == 'P') {
        if (dfs(row - 1, col, visited, game) ||
            dfs(row + 1, col, visited, game) ||
            dfs(row, col - 1, visited, game) ||
            dfs(row, col + 1, visited, game)) {
            return 1;
        }
    }
    return 0;
}

static void validatePath(t_game *game)
{
    int	i;
	
	i = 0;
	int	**visited = (int **)ft_calloc(game->map->size.y, sizeof(int	*));
    while(i < game->map->size.y)
	{
        visited[i] = ft_calloc(game->map->size.x, sizeof(int));
		i++;
	}
    int	pathExists = dfs(game->player->pos.y, game->player->pos.x, visited, game);

	i = 0;
	while(i < game->map->size.y){
    	free(visited[i]);
    	visited[i] = NULL;
    	i++;
	}
	free(visited);
	visited = NULL;
    if (!pathExists)
	{
		map_free(game->map);
		print_error(ERROR_PATH);
	}
}

void map_validate(t_game *game)
{
	t_map *map;

	map = game->map;
	validateItems(game);
	if (map->exit_present != 1 || map->player_present != 1 || map->coins < 1)
	{
		map_free(map);
		print_error(ERROR_ITEMS);
	}
	validateCorners(map);
	validatePath(game);
}
