#ifndef FILLER_H
# define FILLER_H

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

typedef struct		map_list
{
	char			**map;
	int				map_x_size;
	int				map_y_size;
}					m_list;

typedef struct		fig_list
{
	char			**fig;
	int				fig_x_size;
	int				fig_y_size;
	int				pos_x;
	int				pos_y;
}					f_list;

int					p_num; // done
char				sign; // done
int					g_start_pos_x; // done
int					g_start_pos_y; // done
m_list				*g_map; // done
f_list				*g_curr_fig;

char	*ft_findplace(void);
int		ft_fillmap(char *line);
int		ft_readfigure(char *line);
#endif