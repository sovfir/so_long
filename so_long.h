#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 2

# define WALL "./pics/brick.xpm"
# define SPACE "./pics/floor.xpm"
# define PLAYER "./pics/hero.xpm"
# define EXIT_C "./pics/door_closed.xpm"
# define EXIT_O "./pics/door_open.xpm"
# define KEY "./pics/key.xpm"
# define WIN "./graphics/win.xpm"

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>


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
	t_graphics	*graphics;
}				t_data;

int		main(void);
void	main_init(t_data	*main);
void	init_pics(t_data *main);
char	*ft_strchr(char const *string, int symbol);
char	*ft_strjoin_gnl(char *s1, char *s2, char **s3);
size_t	ft_strlen(const char *s);
int		remains_n(char **remains, char **line);
int		buf_check(char *buf);
int		read_file(int fd, char *buf, char **line, ssize_t len);
int		get_next_line(int fd, char **line);
char	*ft_itoa(int n);
char	*ft_strdup(const char	*s1);
int		ft_strncmp(const char	*s1, const char	*s2, size_t n);
char	*ft_substr(char const *s, unsigned int	start, size_t len);



#endif