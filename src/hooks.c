#include "../inc/main.h"
#include <stdio.h>
#include "../inc/structures.h"
#include "../inc/map.h"
#include "../inc/game.h"

int handle_move(t_game *game)
{
    put_map(game->map);
	mlx_put_image_to_window(game->map->mlx, game->map->mlx_win, game->map->player_sprite.ref, game->player->pos.x * BPP, game->player->pos.y * BPP);
	return(0);
}

int check_move(t_game *game, t_point direction)
{
    char    *map_char;
    t_point new_pos;

    new_pos.x = game->player->pos.x + direction.x;
    new_pos.y = game->player->pos.y + direction.y;
    printf("plypos: %d %d\n", game->player->pos.x, game->player->pos.y);
    printf("direction: %d %d\n", direction.x, direction.y);
    printf("newpos: %d %d\n", new_pos.x, new_pos.y);
    map_char = &game->map->buffer[new_pos.y][new_pos.x];
    printf("map_char: %c\n", *map_char);
    if (*map_char == FLOOR_CHAR)
    {
        game->player->pos.x += direction.x;
        game->player->pos.y += direction.y;
    }
    else if (*map_char == COIN_CHAR)
    {
        *map_char = FLOOR_CHAR;
        game->map->coins--;
        game->player->pos.x += direction.x;
        game->player->pos.y += direction.y;
    }
    else if (*map_char == EXIT_CHAR)
    {
        NULL;
        // if (game->map->coins == 0)
        //     game_end(game);
    }
    printf("coins: %d\n", game->map->coins);


    return (0);
}

int key_hook(int key, void *param)
{
    t_game *game = (t_game *)param;
    t_point p;

    p.x = 0;
    p.y = 0;
    printf("Key pressed: %c\n", key);
    if  (key == KEY_RIGHT)
        p.x = 1;
    else if  (key == KEY_LEFT)
        p.x = -1;
    else if  (key == KEY_DOWN)
        p.y = 1;
    else if  (key == KEY_UP)
        p.y = -1;
    else
        {printf("Key not valid");}

    check_move(game, p);
    handle_move(game);

    return (0);
}

int ft_update (void *param)
{
    t_game *game = (t_game *) param;
//    mlx_clear_window(game->map->mlx, game->map->mlx_win);

    handle_move(game);

    return(0);
}