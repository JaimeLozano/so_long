/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 01:01:04 by jlozano-          #+#    #+#             */
/*   Updated: 2023/09/04 21:40:08 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "main.h"

void	create_window(t_game *game);
void	create_sprites(t_game *game);

int		key_hook(int key, void *param);
int		ft_update(void *param);
int		game_end(t_game *game);

#endif