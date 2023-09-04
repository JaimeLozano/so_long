/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:00:43 by jlozano-          #+#    #+#             */
/*   Updated: 2023/09/04 23:47:23 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "game.h"
#include "mlx.h"
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

static void	sprite_put(t_game *g, void *sprite_ref, int x, int y)
{
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, sprite_ref, x, y);
}

void	put_map(t_game *g)
{
	int		i;
	int		j;
	char	pos;

	i = g->map->size.y;
	j = g->map->size.x;
	while (i--)
	{
		while (j--)
		{
			pos = g->map->buffer[i][j];
			if (pos == WALL_CHAR)
				sprite_put(g, g->map->wall_sprite.ref, j * BPP, i * BPP);
			else if (pos == FLOOR_CHAR || pos == PLAYER_CHAR)
				sprite_put(g, g->map->floor_sprite.ref, j * BPP, i * BPP);
			else if (pos == EXIT_CHAR)
				sprite_put(g, g->map->exit_sprite.ref, j * BPP, i * BPP);
			else if (pos == COIN_CHAR)
				sprite_put(g, g->map->coin_sprite.ref, j * BPP, i * BPP);
		}
		j = g->map->size.x;
	}
	sprite_put(g, g->map->player_sprite.ref, \
						g->player->pos.x * BPP, g->player->pos.y * BPP);
}

void	map_print(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size.y)
	{
		ft_printf("%s", map->buffer[i]);
		i++;
	}
	ft_printf("\n");
}

void	read_map(int fd, t_game *game)
{
	int		i;
	char	*tab[100];
	char	*line;
	int		line_size;

	line = get_next_line(fd);
	if (!line)
		print_error(ERROR_TOP);
	tab[0] = line;
	line = get_next_line(fd);
	i = 1;
	while (line)
	{
		tab[i++] = line;
		line = get_next_line(fd);
	}
	game->map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!game->map)
		print_error(ERROR_MEMORY);
	game->map->size.y = i;
	line_size = ft_strlen(tab[0]);
	game->map->size.x = line_size - 1;
	game->map->buffer = (char **)ft_calloc(i, sizeof(char *));
	while (i--)
		game->map->buffer[i] = tab[i];
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
