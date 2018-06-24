#include "../fillit.h"

int		get_min_x(char **piece)
{
	int min_x;
	int i;
	int j;

	min_x = 3;
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
			}
			j++;
		}
		i++;
	}
	return (min_x);
}

int		get_min_y(char **piece)
{
	int min_y;
	int i;
	int j;

	min_y = 3;
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
			}
			j++;
		}
		i++;
	}
	return (min_y);
}

void	fill_struct(t_piece *part, char *buffer)
{
	part->table = make_piece(buffer);
	part->width = get_width((*part).table);
	part->height = get_height((*part).table);
	part->x = get_min_x((*part).table);
	part->y = get_min_y((*part).table);
}

char	**make_piece(char *str)
{
	char	**piece;
	int		i;
	int		j;

	piece = (char **)malloc(sizeof(char *) * 4);
	i = 0;
	while (*str != '\0')
	{
		j = 0;
		piece[i] = (char *)malloc(sizeof(char) * 4);
		while (*str != '\n' && *str != '\0')
		{
			piece[i][j] = *str;
			j++;
			str++;
		}
		if (*str == '\n')
			str++;
		i++;
	}
	return (piece);
}
