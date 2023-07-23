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

t_map	*create_map(int fd)
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
	map->size.x = i;
	map->mlx = tab;
	line_size = ft_strlen(tab[0]);
	printf("line_size %d\n", line_size);
	printf("i %d\n", i);
	// while (i--)
	// 	ft_strncpy(map->buffer[i], tab[i], line_size);
	return (map);
}
