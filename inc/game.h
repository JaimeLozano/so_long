/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 01:01:04 by jlozano-          #+#    #+#             */
/*   Updated: 2023/07/07 01:04:53 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "main.h"

int	create_window(t_game *game);
int	create_sprites(t_game *game);

int key_hook(int key, void *param);
int ft_update (void *param);

#endif