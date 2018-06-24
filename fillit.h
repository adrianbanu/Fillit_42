#ifndef FILLIT_H

# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>

typedef struct	s_piece
{
	char		**table;
	int			x;
	int			y;
	char		id;
	int			width;
	int			height;
}				t_piece;

typedef struct	s_map
{
	char		**table;
	int			size;
}				t_map;

int	piece_fits(t_map square, int i, int j, t_piece part);
void	put_piece(t_map square, int i, int j, t_piece part);
void	remove_piece(t_map square, int i, int j, t_piece part);
int	small(t_map square, t_piece *parts);
void			empty(char *str);
int			get_width(char **piece);
int			get_height(char **piece);
int			get_min_x(char **piece);
int			get_min_y(char **piece);
int			ft_sqrt(int n);
char			**alloc_map(int size);
int			is_valid_file(int file, t_piece *parts);
int			is_invalid_piece(char *piece);
int			has_invalid_char(char *str);
int			has_invalid_format(char *str);
int			count_hashes(char *str);
char			**make_piece(char *str);
int			has_more_fragments(char **piece);
int			count_hash_neighbors(char **piece, int i, int j);
void			fill_struct(t_piece *part, char *buffer);
t_map			make_square(t_piece *parts, int count);
void			print_table(t_map square);
#endif
