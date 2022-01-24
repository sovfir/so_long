#ifndef SO_LONG_H
# define SO_LONG_H


# define WALL "./pics/brick.xpm"
# define SPACE "./pics/floor.xpm"
# define PLAYER "./pics/hero.xpm"
# define EXIT_C "./pics/door_closed.xpm"
# define EXIT_O "./pics/door_open.xpm"
# define KEY "./pics/key.xpm"
# define WIN "./pics/win.xpm"
#  define BUFFER_SIZE 2

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2


# include "mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>


typedef struct s_graphics
{
	void	*wall;
	void	*space;
	void	*key;
	void	*exit_c;
	void	*player;
	void	*win;
}	t_graphics;


typedef struct	s_data {
	int			pos_x;
	int			pos_y;
	int			moves;
	int			door_open;
	int			count_c;
	int			player_c;
	void		*img;
	void		*mlx;
	void		*win;
	void		*mlx_win;
	int			height;
	int			width;
	char		*fn;
	char		**map;
	t_graphics	*graphics;
}				t_data;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *memory, char *tmp);
char	*ft_strchr(char *s, int c);
char	*ft_new_string(char *memory);
char	*ft_put_line(char *memory);
char	*ft_read_string(int fd, char *memory);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	ft_main_init(t_data	*main, char *argv);
void	init_pics(t_data *main);
void	ft_readmap(t_data	*data);
void	ft_mapheight(t_data *data);
void	ft_setchar(t_data	*data);
void	ft_result(t_data	*data);
void	ft_charcheck(t_data	*data);
void	ft_formatcheck(t_data *data);
void	ft_wallcheck(t_data	*data);
void	ft_allcheck(t_data	*data);

int		ft_exit_empty(t_data	*data);
void	ft_put_hero(t_data	*data, int	*j,	int	*i);
void	ft_put_wall(t_data	*data, int	*j, int	*i);
void	ft_put_space(t_data	*data, int	*j, int	*i);
void	ft_put_map(t_data	*data);
int		ft_frame(t_data *data);

// void	ft_move_w(t_data *data);
// void	ft_move_s(t_data *data);
// void	ft_move_a(t_data *data);
// void	ft_move_d(t_data *data);
int		ft_press_button(int keycode, t_data *data);


#endif