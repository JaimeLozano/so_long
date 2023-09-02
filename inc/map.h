/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaime <jaime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 09:07:13 by jaime             #+#    #+#             */
/*   Updated: 2023/09/02 18:34:18 by jaime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "main.h"

void	map_checkName(char *filename);
t_map	*read_map(int fd);
void	map_validate(t_game *game);
int     create_map(t_map *map);
void    put_map(t_game *game);
void	map_free(t_map *map);
void    map_print(t_map *map);
