#include "../fillit.h"

int	has_more_fragments(char **piece)
{
	int		neighbors;
	int		i;
	int		j;

	neighbors = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece[i][j] == '#')
				neighbors += count_hash_neighbors(piece, i, j);
			j++;
		}
		i++;
	}
	if (neighbors == 6 || neighbors == 8)
		return (0);
	return (1);
}

int		count_hash_neighbors(char **piece, int i, int j)
{
	int n;

	n = 0;
	if (i > 0 && piece[i - 1][j] == '#')
		n++;
	if (i < 3 && piece[i + 1][j] == '#')
		n++;
	if (j > 0 && piece[i][j - 1] == '#')
		n++;
	if (j < 3 && piece[i][j + 1] == '#')
		n++;
	return (n);
}

int		count_hashes(char *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		if (*str == '#')
			i++;
		str++;
	}
	return (i);
}
