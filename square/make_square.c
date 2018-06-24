#include "../fillit.h"

int	piece_fits(t_map square, int i, int j, t_piece part)
{
	int x;
	int y;

	y = part.y;
	while (y < 4)
	{
		x = part.x;
		while (x < 4)
		{
			if (part.table[y][x] == '#'
			&& square.table[i + y - part.y][j + x - part.x] != '.')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	put_piece(t_map square, int i, int j, t_piece part)
{
	int x;
	int y;

	y = part.y;
	while (y < 4)
	{
		x = part.x;
		while (x < 4)
		{
			if (part.table[y][x] == '#')
				square.table[i + y - part.y][j + x - part.x] = part.id;
			x++;
		}
		y++;
	}
}

void	remove_piece(t_map square, int i, int j, t_piece part)
{
	int x;
	int y;

	y = part.y;
	while (y < 4)
	{
		x = part.x;
		while (x < 4)
		{
			if (part.table[y][x] == '#')
				square.table[i + y - part.y][j + x - part.x] = '.';
			x++;
		}
		y++;
	}
}

int	small(t_map square, t_piece *parts)
{
	int i;
	int j;

	if ((*parts).id == 0)
		return (0);
	i = 0;
	while (i < (square.size - parts->height + 1))
	{
		j = 0;
		while (j < (square.size - parts->width + 1))
		{
			if (piece_fits(square, i, j, *parts))
			{
				put_piece(square, i, j, *parts);
				if (small(square, parts + 1))
					remove_piece(square, i, j, *parts);
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

t_map	make_square(t_piece *parts, int count)
{
	t_map square;

	square.size = ft_sqrt(count * 4);
	square.table = alloc_map(square.size);
	while (small(square, parts))
	{
		square.table = alloc_map(++(square.size));
	}
	return (square);
}
