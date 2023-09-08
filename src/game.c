/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:23:06 by jlozano-          #+#    #+#             */
/*   Updated: 2023/09/08 18:16:03 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "stdlib.h"
#include "map.h"

void	game_end(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->map->player_sprite.ref);
	mlx_destroy_image(game->mlx_ptr, game->map->wall_sprite.ref);
	mlx_destroy_image(game->mlx_ptr, game->map->floor_sprite.ref);
	mlx_destroy_image(game->mlx_ptr, game->map->coin_sprite.ref);
	mlx_destroy_image(game->mlx_ptr, game->map->exit_sprite.ref);
	map_free(game->map);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
}

t_image	ft_new_sprite(t_game *g, char *path)
{
	t_image	img;

	img.ref = mlx_xpm_file_to_image(g->mlx_ptr, path, &img.size.x, &img.size.y);
	if (!img.ref)
	{
		map_free(g->map);
		print_error(ERROR_SPRITE);
	}
	img.pixels = mlx_get_data_addr(img.ref, &img.bits_per_pixel, \
									&img.line_size, &img.endian);
	return (img);
}

void	create_sprites(t_game *game)
{
	game->map->wall_sprite = ft_new_sprite(game, WALL_IMG);
	game->map->floor_sprite = ft_new_sprite(game, FLOOR_IMG);
	game->map->exit_sprite = ft_new_sprite(game, EXIT_IMG);
	game->map->coin_sprite = ft_new_sprite(game, COIN_IMG);
	game->map->player_sprite = ft_new_sprite(game, PLAYER_IMG);
}

void	create_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, (game->map->size.x) * BPP, \
												game->map->size.y * BPP, NAME);
	if (!game->win_ptr)
	{
		map_free(game->map);
		print_error(ERROR_WINDOW_CREATE);
	}
}
