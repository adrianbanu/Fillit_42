#include "../fillit.h"

void	empty(char *str)
{
	int i;

	i = 0;
	while (i < 21)
	{
		str[i] = 0;
		i++;
	}
}

int	is_invalid_piece(char *str)
{
	char	**piece;

	if (has_invalid_char(str)
			|| count_hashes(str) != 4
			|| has_invalid_format(str))
	{
		return (1);
	}
	piece = make_piece(str);
	if (has_more_fragments(piece))
	{
		return (1);
	}
	free(piece);
	return (0);
}

int	has_invalid_format(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*str != '\0')
	{
		if (*str == '.' || *str == '#')
		{
			i++;
		}
		else
		{
			if (i > 4)
				return (1);
			i = 0;
			j++;
		}
		str++;
	}
	if (j != 3)
		return (1);
	return (0);
}

int	has_invalid_char(char *str)
{
	if (str[0] != '.' && str[0] != '#')
		return (1);
	while (*str != '\0')
	{
		if (*str != '.' && *str != '#' && *str != '\n')
		{
			return (1);
		}
		str++;
	}
	return (0);
}

int	is_valid_file(int file, t_piece *parts)
{
	char	*buffer;
	char	letter;
	char	copy;

	letter = 'A';
	buffer = (char *)malloc(sizeof(char) * 22);
	empty(buffer);
	while (read(file, buffer, 21) != 0)
	{
		if (buffer[19] != '\n')
			return (0);
		copy = buffer[20];
		buffer[19] = 0;
		if (is_invalid_piece(buffer))
			return (0);
		parts->id = letter++;
		fill_struct(parts, buffer);
		parts++;
		empty(buffer);
	}
	if (close(file) != 0 || letter == 'A' || copy != 0)
		return (0);
	free(buffer);
	return ((int)letter - 65);
}
