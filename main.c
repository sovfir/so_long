#include "mlx/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include "so_long.h"

void	ft_allcheck(t_data	*data)
{
	ft_setchar(data);
	ft_charcheck(data);
	ft_formatcheck(data);
	ft_wallcheck(data);
}

int	main(int	argc, char **argv)
{
	t_data	data;

	int		img_width;
	int		img_height;
	if (argc == 2)
	{

		data.mlx = mlx_init();
		ft_main_init(&data, argv[1]);
		ft_mapheight(&data);
		ft_readmap(&data);
		ft_allcheck(&data);
		data.win = mlx_new_window(data.mlx, data.width * 40, data.height * 40, "SO_LONG");

		mlx_loop(data.mlx);
	}
}