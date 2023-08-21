#include "structures.h"
#include "main.h"

void	map_checkName(char *filename);
t_map	*read_map(int fd);
void	map_validate(t_map *map, t_player *player);
int create_map(t_map *map);
void put_map(t_game *game);
void	map_free(t_map *map);
