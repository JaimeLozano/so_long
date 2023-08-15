#include "structures.h"
#include "main.h"

void	map_checkName(char *filename);
t_map	*read_map(int fd);
int	map_validate(t_map *map, t_player *player);
int create_map(t_map *map);
int put_map(t_map *map);
