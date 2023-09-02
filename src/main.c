/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaime <jaime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:03:15 by jlozano-          #+#    #+#             */
/*   Updated: 2023/09/02 17:42:33 by jaime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "mlx.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include "structures.h"
#include "game.h"
#include "main.h"
#include "map.h"

/*
TODO:
+ gestionar leaks
+ contar pasos
- botón X
+ validar mapa
	|_ + camino válido
- makefile (no recompila gnl cuando ha cambiado, recompila libft cuando borro .o pero la lib existe)
- gestionar mallocs cuando hay error
- check size_t casting to int
- quitar printfs
- (pragma rosa del player)
- mapa en consola mostrar entero, no solo tres filas
- ()
*/

int	main(int argc, char **argv)
{
	t_game	game;
	t_player player;
	int		fd;

	if (argc != 2)
	{
		print_error(ERROR_ARGC);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error(ERROR_FD);
	}
	map_checkName(argv[1]);
	game.map = read_map(fd);
	close(fd);
    player.move_counter = 0;
	game.player = &player;
	map_validate(&game);
	create_window(&game);
	create_sprites(&game);
	put_map(&game);
	mlx_key_hook(game.win_ptr, *key_hook, &game);
	mlx_loop(game.mlx_ptr);
	return (SUCCESS);
}

void	print_error(int error_code)
{
	if (error_code == ERROR_ARGC)
		ft_printf("Error\nERROR CODE: %d. Number of arguments error\n", error_code);
	else if (error_code == ERROR_FD)
		ft_printf("Error\nERROR CODE: %d. File descriptor error\n", error_code);
	else if (error_code == ERROR_TOP)
		ft_printf("Error\nERROR CODE: %d. Map error on top row\n", error_code);
	else if (error_code == ERROR_BODY)
		ft_printf("Error\nERROR CODE: %d. Map error on body row\n", error_code);
	else if (error_code == ERROR_BOTTOM)
		ft_printf("Error\nERROR CODE: %d. Map error on bottom row\n", error_code);
	else if (error_code == ERROR_HEIGHT)
		ft_printf("Error\nERROR CODE: %d. Map error height too small\n", error_code);
	else if (error_code == ERROR_ITEMS)
		ft_printf("Error\nERROR CODE: %d. Map error: player, coins or exit not present\n", error_code);
	else if (error_code == ERROR_PATH)
		ft_printf("Error\nERROR CODE: %d. Map error: no path possible from P to E\n", error_code);
	else if (error_code == ERROR_WINDOW_CREATE)
		ft_printf("Error\nERROR CODE: %d. No pointer to window returned\n", error_code);
	exit(1);
}
