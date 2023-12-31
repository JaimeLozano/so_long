/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 01:10:55 by jlozano-          #+#    #+#             */
/*   Updated: 2023/09/08 17:25:56 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "define.h"

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_image
{
	void	*ref;
	t_point	size;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}				t_image;

typedef struct s_map
{
	char	**buffer;
	int		coins;
	int		exit_present;
	int		player_present;
	t_image	wall_sprite;
	t_image	floor_sprite;
	t_image	coin_sprite;
	t_image	exit_sprite;
	t_image	player_sprite;
	t_point	size;
}				t_map;

typedef struct s_player
{
	int		is_enable;
	int		move_counter;
	t_point	pos;
}				t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map;
	t_player	player;
}				t_game;

#endif