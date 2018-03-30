/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:22:00 by mkorniie          #+#    #+#             */
/*   Updated: 2018/03/29 14:22:04 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_refresh_trim(void)
{
	g_currfig->trim_ystart = -1;
	g_currfig->trim_xstart = -1;
	g_currfig->trim_yend = -1;
	g_currfig->trim_xend = -1;
}
void	ft_trimming(void)
{
	int i;
	int z;
	int flag;

	i = -1;
	flag = 0;
	ft_refresh_trim();
	while ((++i < g_currfig->fig_ysize) && (z = -1) == -1)
		while (++z < g_currfig->fig_xsize)
			if ((g_currfig->fig[i][z]) == '*')
			{
				if (flag == 0 && ++flag == 1)
				{
					g_currfig->trim_ystart = i;
					g_currfig->trim_xstart = z;
				}
				if (g_currfig->trim_yend < i)
					g_currfig->trim_yend = i;
				if (g_currfig->trim_xend < z)
					g_currfig->trim_xend = z;
				if (g_currfig->trim_xstart > z)
					g_currfig->trim_xstart = z;
			}
	g_currfig->trim_yheight = g_currfig->trim_yend - g_currfig->trim_ystart + 1;
	g_currfig->trim_xwidth = g_currfig->trim_xend - g_currfig->trim_xstart + 1;
}

void	ft_fillmap_size(char *line)
{
		char		*temp;

		temp = ft_strstr(line, " ") + 1;
		g_map->map_ysize = ft_atoi(temp);
		temp = ft_strstr(temp, " ") + 1;
		g_map->map_xsize = ft_atoi(temp);
		g_map->map = (char**)malloc(sizeof(char*) * (g_map->map_ysize + 1));
		g_map->map[g_map->map_ysize] = NULL;
}

int		ft_fillmap(char *line)
{
	int		n;
	int		len;

	n = -2;
	if (g_map->map_ysize == -1)
		ft_fillmap_size(line);
	free(line);
	if ((++n == -1) && (len = get_next_line(0, &line)) <= 0)
		return (-1);
	while (n < (g_map->map_ysize - 1))
	{
		free(line);
		if ((len = get_next_line(0, &line)) <= 0)
			return (-1);
		n++;
		if (g_currfig->fig != NULL)
			free(g_map->map[n]);
		g_map->map[n] = ft_strdup(line + 4);
		if ((g_start_pos_x == -1) && ft_strchr(line, g_sign))
		{
			g_start_pos_x = ft_strlen(line) - 4 - ft_strlen(ft_strchr(line, g_sign));
			g_start_pos_y = n;
		}
	}
	return (1);
}

int		ft_readfigure(char *line)
{
	char		*temp;
	int			n;
	int			len;

	n = -1;
	temp = ft_strstr(line, " ") + 1;
	g_currfig->fig_ysize = ft_atoi(temp);
	temp = ft_strstr(temp, " ") + 1;
	g_currfig->fig_xsize = ft_atoi(temp);
	g_currfig->fig = (char**)malloc(sizeof(char*) * (g_currfig->fig_ysize + 1));
	g_currfig->fig[g_currfig->fig_ysize] = NULL;
	while (n < (g_currfig->fig_ysize - 1))
	{
		free(line);
		if ((len = get_next_line(0, &line)) <= 0)
			return (-1);
		n++;
		g_currfig->fig[n] = ft_strdup(line);
	}
	ft_trimming();
	return (1);
}
