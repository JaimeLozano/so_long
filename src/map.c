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

void	map_checkName(char *filename)
{
	filename = filename + ft_strlen(filename) - 4;
	if (ft_strncmp(filename, ".ber", 4) != 0)
		exit(1);
}

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

static int	validateItems(t_map *map, t_player *player)
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
		}
		j = map->size.x;
	}
	return(0);
}

static int	checkTopLine(t_map *map, int i)
{
	int	j;

	j = 0;
	while (map->buffer[i][j] == WALL_CHAR)
		j++;
	if (map->size.x != j)
	{
		printf("Top row invalid\n");
		exit(1);
	}
	return (0);
}

static int	checkBottomLine(t_map *map, int i)
{
	int	j;

	j = 0;
	while (map->buffer[i][j] == WALL_CHAR)
		j++;
	if (map->size.x != j)
	{
		printf("Bottom row invalid\n");
		exit(1);
	}
	return (0);
}

static int	checkBodyLine(t_map *map, int i)
{
	int ret;

	ret = 0;
	if (map->buffer[i][0] != WALL_CHAR)
		ret = 1;
	if (map->buffer[i][map->size.x  - 1] != WALL_CHAR)
		ret = 2;
	if ((int)ft_strlen(map->buffer[i]) != map->size.x)
		ret = 3;
	if (ret != 0)
	{
		printf("Body row invalid. Ret = %d\n", ret);
		exit(1);
	}
	return (0);
}

static int	validateCorners(t_map *map)
{
	int	i;

	i = 0;
	checkTopLine(map, i++);
	while (i < (map->size.y - 1))
		checkBodyLine(map, i++);
	checkBottomLine(map, i);
	return (0);
}

int map_validate(t_map *map, t_player *player)
{
	validateItems(map, player);
	if (!map->exit_present || !map->player_present || !map->coins)
	{
		printf("Map invalid");
		exit(1);
	}
	validateCorners(map);
	return (0);
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
	map->size.x = line_size - 1;
	printf("%s", tab[0]);
	printf("%s", tab[1]);
	printf("%s", tab[2]);
	printf("\n");
	printf("i: %d, line_size: %d\n", i, line_size);
//	map->buffer = (char **)ft_calloc(i, sizeof(char *));
	i--;
	map->buffer[i] = (char *)malloc(1 * sizeof(char));
	ft_strlcpy(map->buffer[i], tab[i], ft_strlen(tab[i]) + 1);
	printf("map.buffer[%d]: %s\n", i, map->buffer[i]);
	while (i--)
	{
		map->buffer[i] = (char *)malloc(1 * sizeof(char));
		ft_strlcpy(map->buffer[i], tab[i], ft_strlen(tab[i]));
		printf("map.buffer[%d]: %s\n", i, map->buffer[i]);
	}
	return (map);
}
