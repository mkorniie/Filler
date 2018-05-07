/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:22:19 by mkorniie          #+#    #+#             */
/*   Updated: 2018/03/29 14:22:21 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>

typedef struct		s_map_list
{
	char			**map;
	int				map_xsize;
	int				map_ysize;
}					t_m_list;

typedef struct		s_nmap_list
{
	int				**map;
	int				map_xsize;
	int				map_ysize;
}					t_nm_list;

typedef struct		s_bound_list
{
	int				x_left;
	int				x_right;
	int				y_top;
	int				y_bottom;
}					t_bound_list;

typedef struct		s_fig_list
{
	char			**fig;
	int				fig_xsize;
	int				fig_ysize;
	int				trim_ystart;
	int				trim_xstart;
	int				trim_yend;
	int				trim_xend;
	int				trim_yheight;
	int				trim_xwidth;
	int				pos_x;
	int				pos_y;
}					t_f_list;

typedef struct		s_strategy_list
{
	int				min_dest;
	int				max_y;
	int				max_x;
	int				*res;
	int				flag;
	int				dest;
	int				n_betw;
	int				max_n_betw;
}					t_strategy_list;

int					g_p_num;
char				g_sign;
char				g_enem;
int					g_start_pos_x;
int					g_start_pos_y;
t_m_list			*g_map;
t_nm_list			*g_nummap;
t_f_list			*g_currfig;

int					*ft_getplace(void);
int					ft_fillmap(char *line);
int					ft_readfigure(char *line);
void				ft_refresh_trim(void);
void				ft_trimming(void);
int					ft_setnummap(void);
int					ft_absdestination(int y1, int x1, int y2, int x2);
int					*ft_setres(void);
int					ft_n_between(int fig_y, int fig_x);

#endif
