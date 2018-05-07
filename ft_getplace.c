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

int		ft_find_enemy_closest_dest(int fig_y, int fig_x)
{
	int res;
	int fpos_x;
	int fpos_y;
	int x;
	int y;

	y = 0;
	res = 0;
	while (y < (g_currfig->trim_yheight))
	{
		x = 0;
		while (x < (g_currfig->trim_xwidth))
		{
			fpos_y = y + g_currfig->trim_ystart;
			fpos_x = x + g_currfig->trim_xstart;
			if (g_currfig->fig[fpos_y][fpos_x] == '*')
				if (g_map->map[y + fig_y][x + fig_x] != g_sign)
					res += g_nummap->map[y + fig_y][x + fig_x];
			x++;
		}
		y++;
	}
	return (res);
}

int		ft_n_of_touches(int y, int x)
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

int		*ft_setresall(int *max0, int *max1, int *cord0, int *flag)
{
	int *res;

	if ((res = (int*)malloc(sizeof(int) * 3)) == NULL)
		return (NULL);
	res[0] = -1;
	res[1] = -1;
	res[2] = 0;
	(*cord0) = -1;
	(*flag) = 0;
	(*max0) = g_map->map_ysize - g_currfig->trim_yheight;
	(*max1) = g_map->map_xsize - g_currfig->trim_xwidth;
	return (res);
}

int		*ft_getplace(void)
{
	t_strategy_list	r;
	int				x;
	int				y;

	r.res = ft_setresall(&(r.max_y), &(r.max_x), &y, &(r.flag));
	while (++y <= r.max_y)
	{
		x = -1;
		while (++x <= r.max_x)
			if (ft_n_of_touches(y, x) == 1)
			{
				r.n_betw = ft_n_between(y, x);
				r.dest = ft_find_enemy_closest_dest(y, x);
				if (r.res[0] == -1 || (r.max_n_betw < r.n_betw) \
				|| ((r.max_n_betw == r.n_betw) && (r.min_dest > r.dest)))
				{
					r.min_dest = r.dest;
					r.max_n_betw = r.n_betw;
					r.res[0] = y - g_currfig->trim_ystart;
					r.res[1] = x - g_currfig->trim_xstart;
					r.flag = 1;
				}
			}
	}
	return (r.flag == 0 ? NULL : r.res);
}
