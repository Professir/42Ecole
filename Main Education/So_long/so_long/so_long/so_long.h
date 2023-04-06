#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-macos/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct s_img
{
	void		*img;
	int			*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct s_objs
{
	void		*wall;
	void		*character;
	void		*exs;
	void		*collects;
	void		*floor;
}				t_objs;

typedef struct s_mapctrl
{
	void		*max_x;
	void		*max_y;
}				t_mapctrl;

extern char		**maps;
extern t_vector	*player;
extern t_vector	*ex;
extern int		col_counts;
// extern t_vars	var;
extern t_objs	adr_objs;

size_t			ft_strlen(const char *s);
void			ft_putstr(char *str);
void			check_ber(char *map, t_vars t_data);
char			*ft_strdup(const char *src);
int				count_char(char *str, char s);
char			**ft_double(char *str, char s);
int				count_double(char **str);
void			count_collectables(char **a);
char			*ft_strjoin(char *str1, char *str2);
void			check_pos(char **pos);
void			init_map(char **har, t_vars t_data, t_objs *g_adr_objs);
void			error_log(int error_id);
char			*ft_itoa(int nb);
int				len(long nb);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				charcounter(const char *s, char c);
void			err_fd(int i, char **kaps, char *str);


#endif