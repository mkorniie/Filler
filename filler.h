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
	int				trim_y_start;
	int				trim_x_start;
	int				trim_y_end;
	int				trim_x_end;
	int				trim_y_height;
	int				trim_x_width;
	int				pos_x;
	int				pos_y;
}					f_list;

int					p_num; // done
char				sign; // done
char				g_enem;
int					g_start_pos_x; // done
int					g_start_pos_y; // done
m_list				*g_map; // done
f_list				*g_curr_fig;

int		*ft_getplace(void);
int		ft_fillmap(char *line);
int		ft_readfigure(char *line);

#endif
// 42 / filler VM Developped by: Hcao - Abanlin