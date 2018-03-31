#include "filler.h"

int	ft_destination(int y1, int x1, int y2, int x2)
{
	int res;

	res = (x1 - x2) * (x1 - x2);
	res += (y1 - y2) * (y1 - y2);
	res = ft_sqrt(res);
	return (res);
}

int	*ft_setres(void)
{
	int *res;

	if ((res = (int*)malloc(sizeof(int) * 3)) == NULL)
		return (NULL);
	res[0] = -1;
	res[1] = -1;
	res[2] = 0;
	return (res);
}