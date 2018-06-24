#include "fillit.h"

int	main(int argc, char **argv)
{
	t_piece	*parts;
	int		count;
	int		file;
	t_map	square;

	parts = (t_piece *)malloc(sizeof(t_piece) * 26);
	if (argc == 2)
	{
		if ((file = open(argv[1], O_RDONLY)) != -1
		&& is_valid_file(file, parts))
		{
			count = is_valid_file(file, parts);
			square = make_square(parts, count);
			print_table(square);
		}
		else
			write(1, "error\n", 6);
	}
	else
		write(1, "usage: fillit input_file\n", 25);
	free(parts);
	return (0);
}
