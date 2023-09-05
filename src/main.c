/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlozano- <jlozano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:03:15 by jlozano-          #+#    #+#             */
/*   Updated: 2023/09/05 22:44:10 by jlozano-         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_game		game;
	t_player	player;
	int			fd;

	if (argc != 2)
	{
		print_error(ERROR_ARGC);
	}
	map_check_name(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error(ERROR_FD);
	read_map(fd, &game);
	close(fd);
	game.player = &player;
	map_validate(&game);
	map_print(game.map);
	create_window(&game);
	create_sprites(&game);
	put_map(&game);
	mlx_key_hook(game.win_ptr, *key_hook, &game);
	mlx_hook(game.win_ptr, DESTROY_WINDOW, 0, game_end, &game);
	mlx_loop(game.mlx_ptr);
	return (SUCCESS);
}

void	print_error(int error_code)
{
	if (error_code == ERROR_ARGC)
		ft_printf("Error\nERROR CODE: %d. Nº of arguments error\n", error_code);
	else if (error_code == ERROR_FD)
		ft_printf("Error\nERROR CODE: %d. File descriptor error\n", error_code);
	else if (error_code == ERROR_NAME)
		ft_printf("Error\nERROR CODE: %d. File extension error\n", error_code);
	else if (error_code == ERROR_TOP)
		ft_printf("Error\nERROR CODE: %d. Map error on top row\n", error_code);
	else if (error_code == ERROR_BODY)
		ft_printf("Error\nERROR CODE: %d. Map error on body row\n", error_code);
	else if (error_code == ERROR_BOTTOM)
		ft_printf("Error\nERROR CODE: %d. Map error on bottom row\n", error_code);
	else if (error_code == ERROR_HEIGHT)
		ft_printf("Error\nERROR CODE: %d. Map error height small\n", error_code);
	else if (error_code == ERROR_ITEMS)
		ft_printf("Error\nERROR CODE: %d. Map error items invalid\n", error_code);
	else if (error_code == ERROR_PATH)
		ft_printf("Error\nERROR CODE: %d. Map error no path found\n", error_code);
	else if (error_code == ERROR_WINDOW_CREATE)
		ft_printf("Error\nERROR CODE: %d. No ptr to window given\n", error_code);
	exit(1);
}
