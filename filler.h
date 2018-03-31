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
}					t_f_list;

int					g_p_num;
char				g_sign;
char				g_enem;
int					g_start_pos_x;
int					g_start_pos_y;
t_m_list			*g_map;
t_f_list			*g_currfig;

int		*ft_getplace(void);
int		ft_fillmap(char *line);
int		ft_readfigure(char *line);
int		*ft_setres(void);
int		ft_destination(int y1, int x1, int y2, int x2);

#endif
