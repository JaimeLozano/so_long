/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:00:43 by jlozano-          #+#    #+#             */
/*   Updated: 2023/07/07 08:50:18 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"
#include "../inc/game.h"

int	put_map(t_map *map)
{
	int	i;
	int	j;
	char pos;

	i = map->size.y;
	j = map->size.x;
	while (i--)
	{
		while (j--)
		{
			pos = map->buffer[i][j];
			if (pos == WALL_CHAR)
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->wall_sprite.ref, j * BPP, i * BPP);
			else if (pos == FLOOR_CHAR || pos == PLAYER_CHAR)
				mlx_put_image_to_window(map->mlx, map->mlx_win, map->floor_sprite.ref, j * BPP, i * BPP);
			else if (pos == EXIT_CHAR)
    			mlx_put_image_to_window(map->mlx, map->mlx_win, map->exit_sprite.ref, j * BPP, i * BPP);
			else if (pos == COIN_CHAR)
    			mlx_put_image_to_window(map->mlx, map->mlx_win, map->coin_sprite.ref, j * BPP, i * BPP);
			// else if (pos == PLAYER_CHAR)
    		// 	mlx_put_image_to_window(map->mlx, map->mlx_win, map->player_sprite.ref, j * BPP, i * BPP);
		}
		j = map->size.x;
	}
	return(0);
}

int	validate_map(t_map *map, t_player *player)
{
	int	i;
	int	j;
	char *pos;

	j = map->size.x;
	i = map->size.y;
	while (i--)
	{
		while (j--)
		{
			pos = &map->buffer[i][j];
			if (*pos == WALL_CHAR)
				NULL;
			else if (*pos == FLOOR_CHAR)
				NULL;
			else if (*pos == EXIT_CHAR)
				NULL;
			else if (*pos == COIN_CHAR)
    			map->coins++;
			else if (*pos == PLAYER_CHAR)
			{
				*pos = FLOOR_CHAR;
				player->pos.x = j;
				player->pos.y = i;
			}
		}
		j = map->size.x;
	}
	return(0);
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
	line_size = ft_strlen(tab[0]);
	map->size.x = line_size;
	printf("%s", tab[0]);
	printf("%s", tab[1]);
	printf("%s", tab[2]);
	printf("\n");
	printf("i: %d, line_size: %d\n", i, line_size);
	while (i--)
	{
		map->buffer[i] = (char *)malloc(1 * sizeof(char));
		ft_strlcpy(map->buffer[i], tab[i], line_size);
		printf("map.buffer[%d]: %s\n", i, map->buffer[i]);
	}
	return (map);
}
