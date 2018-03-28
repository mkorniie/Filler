#include "filler.h"
#include <stdio.h>

char	*ft_findplace(void)
{
	char *res;

	res = ft_strdup("0 0\n");
	res[0] = g_start_pos_y + '0';
	res[2] = g_start_pos_x + '0';
	return (res);
}

int		ft_fillmap(char *line)
{
	char		*temp;
	int			n;
	int			len;

	n = -2;
	temp = ft_strstr(line, " ") + 1;
	g_map->map_y_size = ft_atoi(temp);
	// dprintf(2, "MARIA: map_y_size = %d\n", g_map->map_y_size);
	temp = ft_strstr(temp, " ") + 1;
	g_map->map_x_size = ft_atoi(temp);
	// dprintf(2, "MARIA: map_x_size = %d\n", g_map->map_x_size);
	g_map->map = (char**)malloc(sizeof(char*) * (g_map->map_y_size + 1));
	g_map->map[g_map->map_y_size] = NULL;
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
		g_map->map[n] = ft_strdup(line + 4);
		// dprintf(2, "MARIA: g_map->map[%d] is %s\n", n, g_map->map[n]);
		if (ft_strchr(line, sign) && (g_start_pos_x == -1))
		{
			g_start_pos_x = ft_strlen(line) - 4 - ft_strlen(ft_strchr(line, sign));
			// dprintf(2, "MARIA: g_start_pos[x] = %d\n", g_start_pos_x);
			g_start_pos_y = n;
			// dprintf(2, "MARIA: g_start_pos[y] = %d\n", g_start_pos_y);
			// dprintf(2, "MARIA: n is = %d\n", n);
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
	// dprintf(2, "MARIA: fig_y_size = %d\n", g_curr_fig->fig_y_size);
	temp = ft_strstr(temp, " ") + 1;
	g_curr_fig->fig_x_size = ft_atoi(temp);
	// dprintf(2, "MARIA: fig_x_size = %d\n", g_curr_fig->fig_x_size);
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
		// dprintf(2, "MARIA: g_curr_fig->fig[%d] is %s\n", n, g_curr_fig->fig[n]);
	}
	// dprintf(2, "MARIA: outa here!\n");
	return (1);
}