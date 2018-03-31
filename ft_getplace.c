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

int		ft_find_enemy_closest_dest(int y_center, int x_center)
{
	int		*res;
	int		i;
	int		z;
	int		flag;
	int		dest_tmp;
	int		dest;

	if ((res = ft_setres()) == NULL)
		return (-1);
	i = -1;
	flag = 0;
	while (++i < (g_map->map_ysize) && (z = -1) == -1)
		while (++z < (g_map->map_xsize))
		{
			dest_tmp = ft_destination(i, z, y_center, x_center);
			if ((g_map->map[i][z]) == g_enem)
				if (flag == 0 || dest_tmp < dest)
				{
					res[0] = i;
					res[1] = z;
					dest = dest_tmp;
					flag = 1;
				}
		}
	return (dest);
}

int		ft_n_of_touches(int x, int y)
{
	int i;
	int z;
	int fpos_x;
	int fpos_y;
	int n_of_touches;

	i = -1;
	n_of_touches = 0;
	while (++i < (g_currfig->trim_yheight) && ((z = -1) == -1))
		while (++z < (g_currfig->trim_xwidth))
			if (g_map->map[y + i][x + z] == g_sign)
			{
				fpos_y = i + g_currfig->trim_ystart;
				fpos_x = z + g_currfig->trim_xstart;
				if (g_currfig->fig[fpos_y][fpos_x] == '*' && ++n_of_touches > 1)
						return (-1);
			}
			else if (g_map->map[y + i][x + z] != '.')
			{
				fpos_y = i + g_currfig->trim_ystart;
				fpos_x = z + g_currfig->trim_xstart;
				if (g_currfig->fig[fpos_y][fpos_x] == '*')
					return (-1);
			}
	return (n_of_touches == 1 ? 1 : 0);
}

int		ft_coverage(int x, int y)
{
	int res;
	int i;
	int z;

	i = g_currfig->trim_ystart;
	res = 0;
	while (i <= g_currfig->trim_yheight)
	{
		z = g_currfig->trim_xstart;
		while (z <= g_currfig->trim_xwidth)
		{
			if (g_map->map[y + i][x + z] == g_enem)
				res++;
			z++;
		}
		i++;
	}
	return (res);
}

void	ft_setall(int *max0, int *max1, int *cord0, int *cord1, int* a0)
{
	(*a0) = 0;
	(*cord1) = -1;
	(*cord0) = -1;
	(*max0)= g_map->map_ysize - g_currfig->trim_yheight - 1;
	(*max1)= g_map->map_xsize - g_currfig->trim_xwidth - 1;
}

int		*ft_getplace(void)
{
	int		i[2];
	int		cord[2];
	int		max[2];
	int		*res;
	int		a[3];

	res = ft_setres();
	ft_setall(&max[0], &max[1], &cord[0], &cord[1], &a[0]);
	while (++cord[0] <= max[0] && (cord[1] = 0) == 0)
		while (++cord[1] <= max[1])
			if (ft_n_of_touches(cord[1], cord[0]) == 1)
			{
				if ((a[2] = ft_find_enemy_closest_dest(cord[1], cord[0])) < 0)
					return (NULL);
				a[1] = ft_coverage(cord[1],cord[0]);
				if (res[0] == -1 || a[1] > i[1] || ((a[1] == i[1]) && (i[0] > a[2])))
				{
					i[1] = a[1];
					i[0] = a[2];
					res[0] = cord[0] - g_currfig->trim_ystart;
					res[1] = cord[1] - g_currfig->trim_xstart;
					a[0] = 1;
				}
			}
	return (a[0] == 0 ? NULL : res);
}
