/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaime <jaime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:00:43 by jlozano-          #+#    #+#             */
/*   Updated: 2023/09/02 17:36:30 by jaime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "game.h"
#include "mlx.h"
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

void	map_checkName(char *filename)
{
	filename = filename + ft_strlen(filename) - 4;
	if (ft_strncmp(filename, ".ber", 4) != 0)
		print_error(ERROR_NAME);
}

void	put_map(t_game *game)
{
	int	i;
	int	j;
	char pos;
	t_map *map;

	map = game->map;
	i = map->size.y;
	j = map->size.x;
	while (i--)
	{
		while (j--)
		{
			pos = map->buffer[i][j];
			if (pos == WALL_CHAR)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, map->wall_sprite.ref, j * BPP, i * BPP);
			else if (pos == FLOOR_CHAR || pos == PLAYER_CHAR)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, map->floor_sprite.ref, j * BPP, i * BPP);
			else if (pos == EXIT_CHAR)
    			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, map->exit_sprite.ref, j * BPP, i * BPP);
			else if (pos == COIN_CHAR)
    			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, map->coin_sprite.ref, j * BPP, i * BPP);
		}
		j = map->size.x;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->map->player_sprite.ref, game->player->pos.x * BPP, game->player->pos.y * BPP);
}

t_map	*read_map(int fd)
{
	int		i;
	char	*tab[100];
	char	*line;
	t_map	*map;
	int		line_size;

	line = get_next_line(fd);
	if (!line)
		print_error(ERROR_TOP);
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
		print_error(ERROR_MEMORY);
	map->size.y = i;
	line_size = ft_strlen(tab[0]);
	map->size.x = line_size - 1;
	ft_printf("%s", tab[0]);
	ft_printf("%s", tab[1]);
	ft_printf("%s", tab[2]);
	ft_printf("\n");
	ft_printf("i: %d, line_size: %d\n", i, line_size);
	map->buffer = (char **)ft_calloc(i, sizeof(char *));
	while (i--)
		map->buffer[i] = tab[i];
	return (map);
}

void	map_free(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size.y)
	{
		free(map->buffer[i]);
		map->buffer[i] = NULL;
		++i;
	}
	free(map->buffer);
	free(map);
	map = NULL;
}
