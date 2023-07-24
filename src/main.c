/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:03:15 by jlozano-          #+#    #+#             */
/*   Updated: 2023/07/07 08:44:21 by jlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_player player;
	int		fd;
	int		ret;

	if (argc != 2)
	{
		ft_printf("Argument error");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		return (-1);
	}
	game.map = read_map(fd);
	close(fd);
	// ret = validate_map(game.map);
	// ret = create_map(game.map);
	ret = create_window(&game);
	game.player = &player;
	player.pos.x = 1;
	player.pos.y = 1;
	ret = create_sprites(&game);
	handle_move(&game);
	if (ret != 0)
	{
		ft_printf("Init error\n");
		return (-1);
	}
	mlx_key_hook(game.map->mlx_win, *key_hook, &game);
//	mlx_loop_hook(game.map->mlx, *ft_update, &game);
	mlx_loop(game.map->mlx);
	return (0);
}