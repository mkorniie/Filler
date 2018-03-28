#include "filler.h"
#include <stdio.h>

// void	ft_parse(char *line)
// {
// 	static char	flag;
// 	char		*temp;

// 	if (ft_strstr(line, "Plateau") != NULL)
// 	{
// 		flag = 'm';
// 		temp = ft_strstr(line, " ") + 1;
// 		map_x_size = ft_atoi(temp);
// 		printf("map_x_size = %d\n", map_x_size);
// 		temp = ft_strstr(line, " ") + 1;
// 		map_y_size = ft_atoi(temp);
// 		printf("map_y_size = %d\n", map_y_size);
// 	}
// 	else if (ft_strstr(line, "Piece") != NULL)
// 		flag = 'f';
// 	if (flag == 'm')
// 		ft_fillmap(line);
// 	else if (flag == 'f')
// 		ft_readligure(line);
// }
void	ft_setup(void)
{
	p_num = 0;
	sign = 0;
	g_start_pos_x = -1;
	g_start_pos_y = -1;
	g_map = (m_list*)malloc(sizeof(m_list));
	g_map->map = NULL;
	g_map->map_x_size = -1;
	g_map->map_y_size = -1;
	g_curr_fig = (f_list*)malloc(sizeof(f_list));
	g_curr_fig->fig = NULL;
	g_curr_fig->fig_x_size = -1;
	g_curr_fig->fig_y_size = -1;
	g_curr_fig->pos_x = -1;
	g_curr_fig->pos_y = -1;
}
int		main(void)
{
	char *line;
	int len;

	len = 1;
	ft_setup();
	while (len > 0)
	{
		len = get_next_line(0, &line);
		if ((len > 0) && (ft_strstr(line, "mkorniie") != NULL))
		{
			p_num = line[10] - '0';
			sign = (p_num == 1 ? 'O' : 'X');
			// dprintf(2, "MARIA: p_num is [%d]\n", p_num);
		}
		else if ((len > 0) && (ft_strstr(line, "Plateau") != NULL))
		{
			// dprintf(2, "MARIA: go to map!\n");
			if (ft_fillmap(line) == -1)
				return (0);
		}
		else if ((len > 0) && (ft_strstr(line, "Piece") != NULL))
		{
			// dprintf(2, "MARIA: go to writing figure!\n");
			if (ft_readfigure(line) == -1)
				return (0); 
			line = ft_findplace();
			// dprintf(2, "MARIA: writing!\n");
			write(1, line, 4);
			free(line);
		}
	}
	write(2, "\n\n", 2);
	return (0);
}