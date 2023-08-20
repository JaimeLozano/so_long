#include "../inc/main.h"
#include <stdio.h>
#include "../inc/structures.h"
#include "../inc/map.h"
#include "../inc/game.h"

int check_move(t_game *game, t_point direction)
{
    char    *map_char;
    t_point new_pos;

    new_pos.x = game->player->pos.x + direction.x;
    new_pos.y = game->player->pos.y + direction.y;
    map_char = &game->map->buffer[new_pos.y][new_pos.x];
    if (*map_char == FLOOR_CHAR)
    {
        game->player->pos.x += direction.x;
        game->player->pos.y += direction.y;
        game->player->move_counter++;
    }
    else if (*map_char == COIN_CHAR)
    {
        *map_char = FLOOR_CHAR;
        game->map->coins--;
        game->player->pos.x += direction.x;
        game->player->pos.y += direction.y;
        game->player->move_counter++;
        printf("coins: %d\n", game->map->coins);
    }
    else if (*map_char == EXIT_CHAR)
    {
        if (game->map->coins == 0)
            game_end(game);
    }
    printf("movements: %d\n", game->player->move_counter);


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
    put_map(game);

    return (0);
}
