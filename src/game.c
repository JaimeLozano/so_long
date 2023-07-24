/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:23:06 by jlozano-          #+#    #+#             */
/*   Updated: 2023/07/07 10:54:17 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;
	
	img.ref = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels  = mlx_get_data_addr(img.ref, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

int	create_sprites(t_game *game)
{
	game->map->wall_sprite = ft_new_sprite(game->map->mlx, WALL_IMG);
	game->map->floor_sprite = ft_new_sprite(game->map->mlx, FLOOR_IMG);
	game->map->exit_sprite = ft_new_sprite(game->map->mlx, EXIT_IMG);
	game->map->coin_sprite = ft_new_sprite(game->map->mlx, COIN_IMG);
	game->map->player_sprite = ft_new_sprite(game->map->mlx, PLAYER_IMG);
//	mlx_put_image_to_window(game->map->mlx, game->map->mlx_win, game->map->wall_sprite.ref, 0, 0);
//	mlx_put_image_to_window(game->map->mlx, game->map->mlx_win, game->map->player_sprite.ref, game->player->pos.x * BPP, game->player->pos.y * BPP);
	return(0);
}

int	create_window(t_game *game)
{
	game->map->mlx = mlx_init();
	game->map->mlx_win = mlx_new_window(game->map->mlx, game->map->size.x * BPP, game->map->size.y * BPP, "so_long");

	if (!game->map->mlx_win)
	{
		return (-1);
	}
	return (0);
}