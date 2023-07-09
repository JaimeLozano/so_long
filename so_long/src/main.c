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
	ret = init_game(&game, fd);
	close(fd);
	printf("%s:%d: ret:%d\n",__FILE__, __LINE__, ret);
	if (ret != 0)
	{
		ft_printf("Init error");
		return (-1);
	}
	mlx_loop(game.mlx);
	return (0);
}