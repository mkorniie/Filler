/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nummap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 22:09:05 by mkorniie          #+#    #+#             */
/*   Updated: 2018/04/16 22:09:07 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_point_to_enemy_dest(int point_y, int point_x)
{
	int min_destination;
	int current_destination;
	int x;
	int y;

	y = 0;
	min_destination = -1;
	while (y < g_nummap->map_ysize)
	{
		x = 0;
		while (x < g_nummap->map_xsize)
		{
			if (g_map->map[y][x] == g_enem)
			{
				current_destination = ft_absdestination(y, x, point_y, point_x);
				if (min_destination == -1)
					min_destination = current_destination;
				else if (current_destination < min_destination)
					min_destination = current_destination;
			}
			x++;
		}
		y++;
	}
	return (min_destination / 2);
}

void	ft_addnumbers(void)
{
	int x;
	int y;

	y = 0;
	while (y < g_nummap->map_ysize)
	{
		x = 0;
		while (x < g_nummap->map_xsize)
		{
			if (g_nummap->map[y][x] == '.')
				g_nummap->map[y][x] = ft_point_to_enemy_dest(y, x);
			x++;
		}
		y++;
	}
}

int		ft_setnummap(void)
{
	int i;
	int z;

	g_nummap = (t_nm_list*)malloc(sizeof(t_nm_list));
	g_nummap->map_xsize = g_map->map_xsize;
	g_nummap->map_ysize = g_map->map_ysize;
	g_nummap->map = (int**)malloc(sizeof(int*) * (g_nummap->map_ysize + 1));
	g_nummap->map[g_nummap->map_ysize] = NULL;
	i = 0;
	while (i < g_nummap->map_ysize)
	{
		g_nummap->map[i] = (int*)malloc(sizeof(int) * g_nummap->map_xsize);
		z = 0;
		while (z < g_nummap->map_xsize)
		{
			g_nummap->map[i][z] = (int)g_map->map[i][z];
			z++;
		}
		i++;
	}
	ft_addnumbers();
	return (1);
}
