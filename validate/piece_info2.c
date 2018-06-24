#include "../fillit.h"

int		get_width(char **piece)
{
	int min_x;
	int max_x;
	int i;
	int j;

	min_x = 3;
	max_x = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece[i][j] == '#')
			{
				if (j < min_x)
					min_x = j;
				if (j > max_x)
					max_x = j;
			}
			j++;
		}
		i++;
	}
	return (max_x - min_x + 1);
}

int		get_height(char **piece)
{
	int min_y;
	int max_y;
	int i;
	int j;

	min_y = 3;
	max_y = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece[i][j] == '#')
			{
				if (i < min_y)
					min_y = i;
				if (i > max_y)
					max_y = i;
			}
			j++;
		}
		i++;
	}
	return (max_y - min_y + 1);
}
