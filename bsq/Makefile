NAME= bsq
CC= gcc
CFLAGS= -Wall -Wextra -Werror -I
HEADER= ft_include.h
SRC= main.c lib.c error.c solve.c print.c
OBJ= main.o lib.o error.o solve.o print.o
GCH= ft_include.h.gch

all: $(NAME)

$(NAME):
	$(CC) -g -c $(FLAGS) $(HEADER) $(SRC)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f *$(OBJ) $(GCH)

fclean: clean
	rm -f $(NAME)
