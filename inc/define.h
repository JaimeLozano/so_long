/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaime <jaime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 08:54:07 by jaime             #+#    #+#             */
/*   Updated: 2023/09/02 17:54:45 by jaime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H
// Sprites
#define WALL_IMG    "sprites/wall.xpm"
#define FLOOR_IMG    "sprites/floor.xpm"
#define EXIT_IMG  "sprites/exit.xpm"
#define COIN_IMG  "sprites/coin.xpm"
#define PLAYER_IMG  "sprites/player.xpm"

#define BPP 64

#define KEY_UP      'w'
#define KEY_DOWN    's'
#define KEY_LEFT    'a'
#define KEY_RIGHT   'd'

#define WALL_CHAR       '1'
#define FLOOR_CHAR      '0'
#define EXIT_CHAR       'E'
#define COIN_CHAR       'C'
#define PLAYER_CHAR     'P'

//Error return codes
#define SUCCESS             0
#define ERROR_ARGC          1
#define ERROR_FD            2
#define ERROR_NAME          3
#define ERROR_TOP           4
#define ERROR_BODY          5
#define ERROR_BOTTOM        6
#define ERROR_HEIGHT        7
#define ERROR_ITEMS         8
#define ERROR_PATH          9
#define ERROR_WINDOW_CREATE 10
#define ERROR_MEMORY        11

#endif /* DEFINE_H */