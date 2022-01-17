#include "mlx/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include "so_long.h"

int	main(void)
{
	t_data	*data;

	int		img_width;
	int		img_height;


	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 640, 480, "So long!");
	data->graph = malloc(sizeof(t_graphics));
	data->graph->player = mlx_xpm_file_to_image(data->mlx, PLAYER_A, &img_width, &img_height);
	data->graph->wall = mlx_xpm_file_to_image(data->mlx, WALL, &img_width, &img_height);
	data->graph->key = mlx_xpm_file_to_image(data->mlx, KEY, &img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->graph->player, 40 * 3, 40 * 3);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->graph->wall, 5, 5);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->graph->key, 78, 146);

	mlx_loop(data->mlx);
}