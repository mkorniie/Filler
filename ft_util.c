/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 11:09:27 by mkorniie          #+#    #+#             */
/*   Updated: 2018/03/31 11:09:30 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_absdestination(int y1, int x1, int y2, int x2)
{
	int res;

	res = (x1 - x2) * (x1 - x2);
	res += (y1 - y2) * (y1 - y2);
	return (res);
}

int		*ft_setres(void)
{
	int *res;

	if ((res = (int*)malloc(sizeof(int) * 3)) == NULL)
		return (NULL);
	res[0] = -1;
	res[1] = -1;
	res[2] = 0;
	return (res);
}
