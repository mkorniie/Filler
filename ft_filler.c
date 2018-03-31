/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:36:55 by mkorniie          #+#    #+#             */
/*   Updated: 2018/03/29 12:36:59 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_writeout(int *res)
{
	char *line;
	if (res == NULL)
	{
		write(1, "0 0\n", 4);
	}
	else
	{
		line = ft_itoa(res[0]);
		write(1, line, ft_strlen(line));
		free(line);
		write(1, " ", 1);
		line = ft_itoa(res[1]);
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
	}
}

void	ft_setsign(char *line)
{
	g_p_num = line[10] - '0';
	g_sign = (g_p_num == 1 ? 'O' : 'X');
	g_enem = (g_sign == 'O' ? 'X' : 'O');
}

void	ft_setup(int *len)
{
	(*len) = 1;
	g_p_num = 0;
	g_sign = 0;
	g_start_pos_x = -1;
	g_start_pos_y = -1;
	g_map = (t_m_list*)malloc(sizeof(t_m_list));
	g_map->map = NULL;
	g_map->map_xsize = -1;
	g_map->map_ysize = -1;
	g_currfig = (t_f_list*)malloc(sizeof(t_f_list));
	g_currfig->fig = NULL;
	g_currfig->fig_xsize = -1;
	g_currfig->fig_ysize = -1;
}
int		main(void)
{
	char	*line;
	int		*res;
	int		len;

	ft_setup(&len);
	while (len > 0)
	{
		len = get_next_line(0, &line);
		if ((len > 0) && (ft_strstr(line, "mkorniie") != NULL))
			ft_setsign(line);
		else if ((len > 0) && (ft_strstr(line, "Plateau") != NULL))
		{
			if (ft_fillmap(line) == -1)
				return (0);
		}
		else if ((len > 0) && (ft_strstr(line, "Piece") != NULL))
		{
			if (ft_readfigure(line) == -1)
				return (0); 
			res = ft_getplace();
			ft_writeout(res);
		}
	}
	write(2, "\n\n", 2);
	return (0);
}
