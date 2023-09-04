/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 09:07:13 by jaime             #+#    #+#             */
/*   Updated: 2023/09/04 23:43:17 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "structures.h"
# include "main.h"

void	map_check_name(char *filename);
void	read_map(int fd, t_game *game);
void	map_validate(t_game *game);
int		create_map(t_map *map);
void	put_map(t_game *game);
void	map_free(t_map *map);
void	map_print(t_map *map);
void	check_corners(t_map *map);

#endif