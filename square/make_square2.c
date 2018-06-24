#include "../fillit.h"

void	print_table(t_map square)
{
	int i;

	i = 0;
	while (i < square.size)
	{
		write(1, square.table[i], square.size);
		write(1, "\n", 1);
		i++;
	}
	free(square.table);
}

int		ft_sqrt(int n)
{
	int i;

	i = 1;
	while ((i * i) < n)
		i++;
	return (i);
}

char	**alloc_map(int size)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = (char **)malloc(sizeof(char *) * size);
	while (i < size)
	{
		j = 0;
		map[i] = (char *)malloc(sizeof(char) * (size + 1));
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	return (map);
}
