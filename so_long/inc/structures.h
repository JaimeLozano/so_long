/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 01:10:55 by jlozano-          #+#    #+#             */
/*   Updated: 2023/07/07 10:52:23 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_point
{
	int	x;
	int y;
} 		t_point;

typedef struct	s_map
{
	char	**tab;
	t_point	size;
} 			t_map;

typedef struct	s_image
{
	void	*ref;
	t_point	size;
	char	*pixel;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}				t_image;

typedef	struct s_sprite
{
	t_image	*img_map[5];
}			t_sprite;

typedef struct s_player
{
	t_point	pos;
}		t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_sprite	*sprite;
	t_player	*player;
}				t_game;

#endif