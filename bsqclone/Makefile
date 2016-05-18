NAME= bsq
CC= gcc
CFLAGS= -Wall -Wextra -Werror -I
HEADER= ft_include.h
SRC= main.c list.c lib.c error.c solve.c print.c ft_strjoin.c
OBJ= main.o list.o lib.o error.o solve.o print.o ft_strjoin.o
GCH= ft_include.h.gch

all: $(NAME)

$(NAME):
	$(CC) -g -c $(FLAGS) $(HEADER) $(SRC)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f *$(OBJ) $(GCH)

fclean: clean
	rm -f $(NAME)
