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

int		ft_destination(int y1, int x1, int y2, int x2)
{
	int res;

	res = (x1 - x2) * (x1 - x2);
	res += (y1 - y2) * (y1 - y2);
	res = ft_sqrt(res);
	return (res);
}

int			ft_find_enemy_closest_dest(int y_center, int x_center)
{
	int		*res;
	int		i;
	int		z;
	int		flag;
	int		dest_tmp;
	int		dest;

	if ((res = (int*)malloc(sizeof(int) * 3)) == NULL)
		return (NULL);
	res[0] = -1;
	res[1] = -1;
	res[2] = 0;
	i = -1;
	flag = 0;
	// enem_y = -1;
	// enem_x = -1;
	// x_end = -1;
	// y_end = -1;
	while (++i < (g_map->map_y_size))
	{
		z = -1;
		while (++z < (g_map->map_x_size))
		{
			dest_tmp = ft_destination(i, z, y_center, x_center);
			if ((g_map->map[i][z]) == g_enem)
			{
				if (flag == 0)
				{
					res[0] = i;
					res[1] = z;
					dest = dest_tmp;
					flag = 1;
				}
				if (dest_tmp < dest)
				{
					res[0] = i;
					res[1] = z;
					dest = dest_tmp;
				}
			}
		}
	}
	// res[0] = ;
	// res[1] = (x_start + x_end) / 2;
	// res[0] = y_end; 
	// res[1] = x_end;
	return (dest);
}

// int		ft_findindexz(int x, int y)
// {
// 	int *closest;
// 	int x_center;
// 	int y_center;
// 	int destination;

// 	y_center = y + ((g_curr_fig->trim_y_height)/2 + 1);
// 	x_center = x + ((g_curr_fig->trim_x_end)/2 + 1);
// 	closest = ft_find_enemy_closest(y_center, x_center);
// 	destination = ((x_corner - center[1]) * (x_corner - center[1]));
// 	destination += ((y_corner - center[0]) * (y_corner - center[0]));
// 	return (destination);
// }

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
			z++;
		}
		i++;
	}
	if (n_of_touches == 1)
	{
		return (1);
	}
	return (0);
}

int		ft_coverage(int x, int y)
{
	int res;
	int i;
	int z;

	// dprintf(2, "MARIA: 1\n");
	i = g_curr_fig->trim_y_start;
	// dprintf(2, "MARIA: 2\n");
	res = 0;
	// dprintf(2, "MARIA: 3\n");
	// dprintf(2, "MARIA: 4: x is [%d]; y is [%d] \n", x, y);
	// dprintf(2, "MARIA: 4: trim_x_start is [%d]; trim_x_end is [%d] \n", g_curr_fig->trim_x_start, g_curr_fig->trim_x_end);
	// dprintf(2, "MARIA: 4: trim_y_start is [%d]; trim_y_end is [%d] \n", g_curr_fig->trim_y_start, g_curr_fig->trim_y_end);
	while (i <= g_curr_fig->trim_y_height)
	{
		// dprintf(2, "MARIA: 4: i is [%d]; g_curr_fig->trim_y_end is [%d] \n", i, g_curr_fig->trim_y_end);
		z = g_curr_fig->trim_x_start;
		// dprintf(2, "MARIA: 5\n");
		while (z <= g_curr_fig->trim_x_width)
		{
			// dprintf(2, "MARIA: 7: z is [%d]\n", z);
			// dprintf(2, "MARIA: 7.5: y + i is [%d], x + z is [%d]\n", y + i, x + z);
			if (g_map->map[y + i][x + z] == g_enem)
			{
				// dprintf(2, "MARIA: 8: y + i is [%d], x + z is [%d]\n", y + i, x + z);
				res++;
			}
			z++;
		}
		i++;
	}
	// dprintf(2, "MARIA: 9\n");
	return (res);
}

// int	ft_ifborder(int x, int y)
// {
// 	int res;
// 	int i;
// 	int z;

// 	i = g_curr_fig->trim_y_start;
// 	res = 0;
// 	while (i <= g_curr_fig->trim_y_end)
// 	{
// 		z = g_curr_fig->trim_x_start;
// 		while (z <= g_curr_fig->trim_x_end)
// 		{
// 			if (g_curr_fig->fig[i][z] == '*')
// 				if (i + y == g_map->map_y_size || z + x == g_map->map_x_size)
// 				{
// 					dprintf(2, "MARIA: ft_ifborder! border found\n");
// 					return (1);
// 				}
// 			z++;
// 		}
// 		i++;
// 	}
// 	dprintf(2, "MARIA: ft_ifborder res is [%d]\n", res);
// 	return (0);
// }

// int		ft_ifborder(int x, int y)
// {

// }

int		*ft_findpos(void)
{
	int		index[3];
	int		x;
	int		y;
	int		max_y;
	int 	max_x;
	int		*res;
	int		flag;
	int		cover;
	int		dest;

	x = 0;
	y = 0;
	res = NULL;
	res = (int*)malloc(sizeof(int) * 3);
	res[0] = -1;
	res[1] = -1;
	res[2] = 0;
	flag = 0;
	max_y = g_map->map_y_size - g_curr_fig->trim_y_height - 1;
	max_x = g_map->map_x_size - g_curr_fig->trim_x_width - 1;
	while (y <= max_y)
	{
		x = 0;
		while (x <= max_x)
		{
			if (ft_n_of_touches(x, y) == 1)
			{
				dest = ft_find_enemy_closest_dest(x, y);
				cover = ft_coverage(x,y);
				// border = ft_ifborder(x, y);
				if (res[0] == -1)
				{
					// dprintf(2, "MARIA: res[0] == -1\n");
					// index[2] = border;
					index[1] = cover;
					index[0] = dest;
					res[0] = y - g_curr_fig->trim_y_start;
					res[1] = x - g_curr_fig->trim_x_start;
					flag = 1;
				}
				if (cover > index[1])
				{
					// dprintf(2, "MARIA: cover > index[1]\n");
					index[1] = cover;
					index[0] = dest;
					res[0] = y - g_curr_fig->trim_y_start;
					res[1] = x - g_curr_fig->trim_x_start;
					flag = 1;
				}
				// else if (cover > index[1])
				// {

				// }
				else if ((cover == index[1]) && (index[0] > dest))
				{
					// dprintf(2, "MARIA: res[0] == -1\n");
					// index[2] = border;
					index[1] = cover;
					index[0] = dest;
					res[0] = y - g_curr_fig->trim_y_start;
					res[1] = x - g_curr_fig->trim_x_start;
					flag = 1;
				}

				// cover = ft_coverage(x,y);
				// dest = ft_findindexz(x, y);
				// // border = ft_ifborder(x, y);
				// dprintf(2, "MARIA: n_of_touches is 1. What's next?\n");
				// if (res[0] == -1)
				// {
				// 	dprintf(2, "MARIA: res[0] == -1\n");
				// 	// index[2] = border;
				// 	index[1] = cover;
				// 	index[0] = dest;
				// 	res[0] = y - g_curr_fig->trim_y_start;
				// 	res[1] = x - g_curr_fig->trim_x_start;
				// 	flag = 1;
				// }
				// else if (cover > index[1])
				// {
				// 	dprintf(2, "MARIA: cover > index[1]\n");
				// 	index[1] = cover;
				// 	index[0] = dest;
				// 	res[0] = y - g_curr_fig->trim_y_start;
				// 	res[1] = x - g_curr_fig->trim_x_start;
				// 	flag = 1;
				// }
				// // else if (cover > 0 && (border == 1))
				// // {
				// // 	dprintf(2, "MARIA: cover > 0 && (border == 1)\n");
				// // 	index[1] = cover;
				// // 	index[0] = dest;
				// // 	res[0] = y - g_curr_fig->trim_y_start;
				// // 	res[1] = x - g_curr_fig->trim_x_start;
				// // 	flag = 2;
				// // }
				// else if ((cover == index[1]) && (dest < index[0]))
				// {
				// 	dprintf(2, "MARIA: (cover == index[1]) && (dest < index[0])\n");
				// 	index[0] = dest;
				// 	res[0] = y - g_curr_fig->trim_y_start;
				// 	res[1] = x - g_curr_fig->trim_x_start;
				// 	flag = 1;
				// }
			}
			x++;
		}
		y++;
	}
	// dprintf(2, "MARIA: pos is [%d] [%d]\n", res[0], res[1]);
	// ft_fits()
	// ft_find_enemy_center();
	if (flag == 0)
		return (NULL);
	// if (flag == 3)
		// dprintf(2, "MARIA: ITS BOOOOORED\n");
	return (res);
}

int		*ft_getplace(void)
{
	int *res;

// dprintf(2, "MARIA: ft_getplace here!\n");
	res = ft_findpos();
	// dprintf(2, "MARIA: ft_getplace there!\n");
	return (res);
}
