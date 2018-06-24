NAME = fillit.a

FILES = validate/*.c square/*.c main.c
OBJECTS = *.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME);

$(NAME):
	@gcc $(FLAGS) -c $(FILES)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@gcc $(FLAGS) -o fillit $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f fillit

re: fclean	all
