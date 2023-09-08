/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:45:05 by jlozano-          #+#    #+#             */
/*   Updated: 2023/09/08 17:56:00 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "ft_printf.h"

void	map_check_name(char *filename)
{
	if (ft_strlen(filename) < 4)
		print_error(ERROR_NAME);
	filename = filename + ft_strlen(filename) - 4;
	if (ft_strncmp(filename, ".ber", 4) != 0)
		print_error(ERROR_NAME);
}

static void	check_corner_top(t_map *map, int i)
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

static void	check_corner_body(t_map *map, int i)
{
	int	ret;

	ret = 0;
	if (map->buffer[i][0] != WALL_CHAR)
		ret = 1;
	if (map->buffer[i][map->size.x - 1] != WALL_CHAR)
		ret = 2;
	if ((int)ft_strlen(map->buffer[i]) - 1 != map->size.x)
		ret = 3;
	if (ret != 0)
	{
		map_free(map);
		print_error(ERROR_BODY);
	}
}

static void	check_corner_bottom(t_map *map, int i)
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

void	check_corners(t_map *map)
{
	int	i;

	i = 0;
	check_corner_top(map, i++);
	while (i < (map->size.y - 1))
		check_corner_body(map, i++);
	check_corner_bottom(map, i);
}
