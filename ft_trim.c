/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 10:16:57 by mkorniie          #+#    #+#             */
/*   Updated: 2018/03/31 10:16:59 by mkorniie         ###   ########.fr       */
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
