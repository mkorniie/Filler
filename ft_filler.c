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
#include <stdio.h>

void	ft_writeout(int *res)
{
	// dprintf(2, "MARIA: writing WATT???!\n");
	// ft_putstr_fd( "MARIA: writing WATT?!\n", 2);
	char *line;
	if (res == NULL)
	{
		// dprintf(2, "MARIA: writing NULLLLLLLLL!\n");
		write(1, "0 0\n", 4);
	}
	else
	{
		line = ft_itoa(res[0]);
		// dprintf(2, "MARIA: writing!\n");
		write(1, line, ft_strlen(line));
		// dprintf(2, "MARIA: writing! line is [%s]\n", line);
		free(line);
		write(1, " ", 1);
		line = ft_itoa(res[1]);
		write(1, line, ft_strlen(line));
		// dprintf(2, "MARIA: writing! line is [%s]\n", line);
		write(1, "\n", 1);
		free(line);
	}
}

void	ft_setup(void)
{
	p_num = 0;
	sign = 0;
	g_start_pos_x = -1;
	g_start_pos_y = -1;
	g_map = (m_list*)malloc(sizeof(m_list));
	g_map->map = NULL;
	g_map->map_x_size = -1;
	g_map->map_y_size = -1;
	g_curr_fig = (f_list*)malloc(sizeof(f_list));
	g_curr_fig->fig = NULL;
	g_curr_fig->fig_x_size = -1;
	g_curr_fig->fig_y_size = -1;
	g_curr_fig->pos_x = -1;
	g_curr_fig->pos_y = -1;
}
int		main(void)
{
	char	*line;
	int		*res;
	int		len;

	len = 1;
	ft_setup();
	while (len > 0)
	{
		len = get_next_line(0, &line);
		if ((len > 0) && (ft_strstr(line, "mkorniie") != NULL))
		{
			p_num = line[10] - '0';
			sign = (p_num == 1 ? 'O' : 'X');
			g_enem = (sign == 'O' ? 'X' : 'O');
			// dprintf(2, "MARIA: player_number is [%d]\n", p_num);
		}
		else if ((len > 0) && (ft_strstr(line, "Plateau") != NULL))
		{
			// dprintf(2, "MARIA: go to map!\n");
			if (ft_fillmap(line) == -1)
				return (0);
		}
		else if ((len > 0) && (ft_strstr(line, "Piece") != NULL))
		{
			// dprintf(2, "MARIA: go to writing figure!\n");
			if (ft_readfigure(line) == -1)
			{
				// dprintf(2, "MARIA: 1!\n");
				return (0); 
			}
			// dprintf(2, "MARIA: 2!\n");
			res = ft_getplace();
			// dprintf(2, "MARIA: 3!\n");
			ft_writeout(res);
		}
	}
	write(2, "\n\n", 2);
	return (0);
}
