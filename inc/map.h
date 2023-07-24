#include "structures.h"
#include "main.h"

t_map	*read_map(int fd);
int	validate_map(t_map *map, t_player *player);
int create_map(t_map *map);
int put_map(t_map *map);
