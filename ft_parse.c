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
#include <stdio.h>

void	ft_refresh_trim(void)
{
	g_curr_fig->trim_y_start = -1;
	g_curr_fig->trim_x_start = -1;
	g_curr_fig->trim_y_end = -1;
	g_curr_fig->trim_x_end = -1;
}
void	ft_trimming(void)
{
	int i;
	int z;
	int flag;

	i = -1;
	flag = 0;
	ft_refresh_trim();
	while (++i < g_curr_fig->fig_y_size)
	{
		z = -1;
		while (++z < g_curr_fig->fig_x_size)
			if ((g_curr_fig->fig[i][z]) == '*')
			{
				if ((flag == 0))
				{
					g_curr_fig->trim_y_start = i;
					g_curr_fig->trim_x_start = z;
					flag = 1;
				}
				// dprintf(2, "MARIA: trim: we are on %s[%d][%d] - [%c]\n", g_curr_fig->fig[i], i, z, g_curr_fig->fig[i][z]);
				if (g_curr_fig->trim_y_end < i)
					g_curr_fig->trim_y_end = i;
				if (g_curr_fig->trim_x_end < z)
					g_curr_fig->trim_x_end = z;
				if (g_curr_fig->trim_x_start > z)
					g_curr_fig->trim_x_start = z;
			}
	}
	g_curr_fig->trim_y_height = g_curr_fig->trim_y_end - g_curr_fig->trim_y_start + 1;
	g_curr_fig->trim_x_width = g_curr_fig->trim_x_end - g_curr_fig->trim_x_start + 1;
	// dprintf(2, "MARIA: trim_y_start is = %d\n", g_curr_fig->trim_y_start );
	// dprintf(2, "MARIA: trim_x_start is = %d\n", g_curr_fig->trim_x_start );
	// dprintf(2, "MARIA: trim_y_end is = %d\n", g_curr_fig->trim_y_end );
	// dprintf(2, "MARIA: trim_x_end is = %d\n", g_curr_fig->trim_x_end );
}

void	ft_fillmap_size(char *line)
{
		char		*temp;

		temp = ft_strstr(line, " ") + 1;
		g_map->map_y_size = ft_atoi(temp);
		temp = ft_strstr(temp, " ") + 1;
		g_map->map_x_size = ft_atoi(temp);
		g_map->map = (char**)malloc(sizeof(char*) * (g_map->map_y_size + 1));
		g_map->map[g_map->map_y_size] = NULL;
}

int		ft_fillmap(char *line)
{
	int			n;
	int			len;

	n = -2;
	if (g_map->map_y_size == -1)
		ft_fillmap_size(line);
	free(line);
	if ((len = get_next_line(0, &line)) <= 0)
		return (-1);
	n++;
	while (n < (g_map->map_y_size - 1))
	{
		free(line);
		if ((len = get_next_line(0, &line)) <= 0)
			return (-1);
		n++;
		// dprintf(2, "MARIA: n is %d\n",n);
		// dprintf(2, "MARIA: line is %s\n", line);
		if (g_curr_fig->fig != NULL)
			free(g_map->map[n]);
		g_map->map[n] = ft_strdup(line + 4);
		// dprintf(2, "MARIA: g_map->map[%d] is %s\n", n, g_map->map[n]);
		if ((g_start_pos_x == -1) && ft_strchr(line, sign))
		{
			g_start_pos_x = ft_strlen(line) - 4 - ft_strlen(ft_strchr(line, sign));
			// dprintf(2, "MARIA: g_start_pos[x] = %d\n", g_start_pos_x);
			g_start_pos_y = n;
			// dprintf(2, "MARIA: g_start_pos[y] = %d\n", g_start_pos_y);
			// // dprintf(2, "MARIA: n is = %d\n", n);
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
	g_curr_fig->fig_y_size = ft_atoi(temp);
	dprintf(2, "MARIA: fig_y_size = %d\n", g_curr_fig->fig_y_size);
	temp = ft_strstr(temp, " ") + 1;
	g_curr_fig->fig_x_size = ft_atoi(temp);
	dprintf(2, "MARIA: fig_x_size = %d\n", g_curr_fig->fig_x_size);
	g_curr_fig->fig = (char**)malloc(sizeof(char*) * (g_curr_fig->fig_y_size + 1));
	g_curr_fig->fig[g_curr_fig->fig_y_size] = NULL;
	while (n < (g_curr_fig->fig_y_size - 1))
	{
		free(line);
		if ((len = get_next_line(0, &line)) <= 0)
			return (-1);
		n++;
		// dprintf(2, "MARIA: n is %d\n",n);
		// dprintf(2, "MARIA: line is %s\n", line);
		g_curr_fig->fig[n] = ft_strdup(line);
		dprintf(2, "MARIA: g_curr_fig->fig[%d] is %s\n", n, g_curr_fig->fig[n]);
	}
	dprintf(2, "MARIA: trimming!\n");
	ft_trimming();
	dprintf(2, "MARIA: outa here!\n");
	return (1);
}
