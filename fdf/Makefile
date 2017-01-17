# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoudin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/14 16:43:40 by aoudin            #+#    #+#              #
#    Updated: 2017/01/14 16:48:05 by aoudin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CCF = gcc -Wall -Wextra -Werror

RM = rm -f

LIBS = -LLibs/libft/ -LLibs/minilibx_macos/

SRCS =srcs/b	resenham.c \
	  srcs/creat_lst.c \
	  srcs/main.c

OBJ = $(SRCS:.c=.o)

$(NAME) : $(OBJ)
	@make -s -C libs/libft
	@echo "Libft Compiled"
	@make -s -C libs/minilibx_macos
	@echo "Minilibx Compiled"
	@$(CCF) $(LIBS) -lft -lmlx -framework OpenGL -framework AppKit -o $@ $^
	@echo "Fdf Compiled"

all : $(NAME)

%.o: %.c
	@$(CCF) -o $@ -c $<

clean :
	@make clean -s -C libs/libft
	@echo ".o Libft delete"
	@make clean -s -C libs/minilibx_macos
	@echo ".o Minilibx delete"
	@$(RM) $(OBJ)
	@echo ".o Fdf delete"

fclean : clean
	@$(RM) libs/libft/libft.a
	@echo "libft.a delete"
	@$(RM) libs/minilibx_macos/libmlx.a
	@echo "libmlx.a delete"
	@$(RM) $(NAME)
	@echo "fdf delete"

re : fclean all
