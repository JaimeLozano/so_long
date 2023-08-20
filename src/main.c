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

/*
TODO:
- gestionar leaks
+ contar pasos
- botón X
+ validar mapa
- makefile (no recompila gnl cuando ha cambiado, recompila libft cuando borro .o pero la lib existe)
- puedo utilizar exit(1)? map.c l.20
- gestionar mallocs cuando hay error
- check size_t casting to int
- quitar printfs
- (pragma rosa del player)
- ()
*/

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
	map_checkName(argv[1]);
	game.map = read_map(fd);
	close(fd);
    player.move_counter = 0;
	game.player = &player;
	ret = map_validate(game.map, game.player);
	ret = create_window(&game);
	ret = create_sprites(&game);
	handle_move(&game);
	if (ret != 0)
	{
		ft_printf("Init error\n");
		return (-1);
	}
	mlx_key_hook(game.win_ptr, *key_hook, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}