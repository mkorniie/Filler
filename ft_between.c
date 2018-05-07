/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_between.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:40:37 by mkorniie          #+#    #+#             */
/*   Updated: 2018/04/22 18:40:40 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_addfig(t_bound_list *list, int fig_y, int fig_x)
{
	list->y_top = fig_y;
	list->y_bottom = fig_y + g_currfig->trim_yheight;
	list->x_left = fig_x;
	list->x_right = fig_x + g_currfig->trim_xwidth;
}

t_bound_list	*ft_newboundlist(void)
{
	t_bound_list *new;

	new = (t_bound_list*)malloc(sizeof(t_bound_list));
	new->x_left = -1;
	new->y_top = -1;
	new->x_right = -1;
	new->y_bottom = -1;
	return (new);
}

t_bound_list	*ft_fill_new(char my_char, int fig_y, int fig_x)
{
	t_bound_list	*new;
	int				y;
	int				x;

	new = ft_newboundlist();
	ft_addfig(new, fig_y, fig_x);
	y = -1;
	while (++y < g_map->map_ysize)
	{
		x = -1;
		while (++x < g_map->map_xsize)
			if (g_map->map[y][x] == my_char)
			{
				if (new->x_left < x)
					new->x_left = x;
				if (new->x_right > x)
					new->x_right = x;
				if (new->y_bottom < y)
					new->y_bottom = y;
				if (new->y_top > y)
					new->y_top = y;
			}
	}
	return (new);
}

int				ft_n_between(int fig_y, int fig_x)
{
	int				res;
	int				y;
	int				x;
	t_bound_list	*me;

	me = ft_fill_new(g_sign, fig_y, fig_x);
	res = 0;
	y = 0;
	while (y < g_map->map_ysize)
	{
		x = 0;
		while (x < g_map->map_xsize)
		{
			if (g_map->map[y][x] == g_enem)
			{
				if ((y > me->y_top) && (y < me->y_bottom))
					if ((x > me->x_left) && (x < me->x_right))
						res++;
			}
			x++;
		}
		y++;
	}
	free(me);
	return (res);
}
