/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getplace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:21:49 by mkorniie          #+#    #+#             */
/*   Updated: 2018/03/29 14:21:51 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int		*ft_find_enemy_center(void)
{
	int		*res;
	int		i;
	int		z;
	int		flag;
	char	enem;
	int		x_start;
	int		y_start;
	int		x_end;
	int		y_end;

	res = (int*)malloc(sizeof(int) * 3);
	res[0] = -1;
	res[1] = -1;
	res[2] = 0;
	i = -1;
	flag = 0;
	enem = (sign == 'O' ? 'X' : 'O');
	while (++i < (g_map->map_y_size))
	{
		z = -1;
		while (++z < (g_map->map_x_size))
			if ((g_curr_fig->fig[i][z]) == enem)
			{
				if ((flag == 0))
				{
					y_start = i;//g_curr_fig->trim_y_start = i;
					x_start = z;//g_curr_fig->trim_x_start = z;
					flag = 1;
				}
				// dprintf(2, "MARIA: trim: we are on %s[%d][%d] - [%c]\n", g_curr_fig->fig[i], i, z, g_curr_fig->fig[i][z]);
				if (y_end < i)
					y_end = i;
				if (x_end < z)
					x_end = z;
				if (x_start > z)
					x_start = z;
			}
	}
	res[0] = (y_start + y_end) / 2;
	res[1] = (x_start + x_end) / 2;
	return (res);
}

int		ft_findindex(int x, int y)
{
	int *center;
	int x_corner;
	int y_corner;
	int destination;

	// center = ft_find_enemy_center();
	center = (int*)malloc(sizeof(int) * 3);
	center[0] = 0;
	center[1] = 0;
	center[2] = 0;
	y_corner = y + g_curr_fig->trim_y_end;
	x_corner = x + g_curr_fig->trim_x_end;
	destination = ((x_corner - center[1]) * (x_corner - center[1])) + ((y_corner - center[0]) * (y_corner - center[0]));
	dprintf(2, "MARIA: destination is [%d]\n", destination);
	return (destination);
}

int		ft_n_of_touches(int x, int y)
{
	int i;
	int z;
	int fpos_x;
	int fpos_y;
	int n_of_touches;

	i = 0;
	n_of_touches = 0;
	while (i < (g_curr_fig->trim_y_height))
	{
		z = 0;
		while (z < (g_curr_fig->trim_x_width))
		{
			if (g_map->map[y + i][x + z] == sign)
			{
				fpos_y = i + g_curr_fig->trim_y_start;
				fpos_x = z + g_curr_fig->trim_x_start;
				if (g_curr_fig->fig[fpos_y][fpos_x] == '*')
				{
					if (++n_of_touches > 1)
						return (-1);
				}
			}
			else if (g_map->map[y + i][x + z] != '.')
			{
				fpos_y = i + g_curr_fig->trim_y_start;
				fpos_x = z + g_curr_fig->trim_x_start;
				if (g_curr_fig->fig[fpos_y][fpos_x] == '*')
					return (-1);
			}
			// if (map[y + i][x + z] == (sign + 'a' - 'A'))
			// 	return (1);
			z++;
		}
		i++;
	}
	if (n_of_touches == 1)
		return (1);
	return (0);
}

int		*ft_findpos(void)
{
	int		index;
	int		x;
	int		y;
	int		max_y;
	int 	max_x;
	int		*res;
	int		flag;

	x = 0;
	y = 0;
	res = NULL;
	index = 2;
	res = (int*)malloc(sizeof(int) * 3);
	res[0] = -1;
	res[1] = -1;
	res[2] = 0;
	flag = 0;
	max_y = g_map->map_y_size - g_curr_fig->trim_y_height;
	dprintf(2, "MARIA: max_y is [%d]\n", max_y);
	max_x = g_map->map_x_size - g_curr_fig->trim_x_width;
	dprintf(2, "MARIA: max_x is [%d]\n", max_x);
	while (y <= max_y)
	{
		x = 0;
		while (x <= max_x)
		{
			if (ft_n_of_touches(x, y) == 1)
			{
				dprintf(2, "MARIA: n_of_touches is 1. What's next?\n");
				if (ft_findindex(x, y) < index)
				{
					dprintf(2, "ft_findindex(x, y) > index. What's next?\n");
					index = ft_findindex(x, y);
					dprintf(2, "index = ft_findindex(x, y). What's next?\n");
					res[0] = y - g_curr_fig->trim_y_start;
					res[1] = x - g_curr_fig->trim_x_start;
					flag = 1;
				}
			}
			x++;
		}
		y++;
	}
	dprintf(2, "MARIA: pos is [%d] [%d]\n", res[0], res[1]);
	// ft_fits()
	// ft_find_enemy_center();
	if (flag == 0)
		return (NULL);
	return (res);
}

int		*ft_getplace(void)
{
	int *res;

	res = ft_findpos();
	return (res);
}
