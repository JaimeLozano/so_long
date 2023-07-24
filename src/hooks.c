#include "../inc/main.h"
#include <stdio.h>
#include "../inc/structures.h"
#include "../inc/map.h"

int handle_move(t_game *game)
{
    put_map(game->map);
	mlx_put_image_to_window(game->map->mlx, game->map->mlx_win, game->map->player_sprite.ref, game->player->pos.x * BPP, game->player->pos.y * BPP);
	return(0);
}

int key_hook(int key, void *param)
{
    t_game *game = (t_game *)param;
    printf("Key pressed: %c\n", key);
    if  (key == 'a')
        game->player->pos.x--;
    else if  (key == 'd')
        game->player->pos.x++;
    else if  (key == 'w')
        game->player->pos.y--;
    else if  (key == 's')
        game->player->pos.y++;
    else
        {printf("Key not valid");}

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