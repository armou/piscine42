# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoudin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/14 16:43:40 by aoudin            #+#    #+#              #
#    Updated: 2017/02/02 12:09:14 by aoudin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

LIBS = -LLibs/libft/ -LLibs/minilibx_macos/

SRCS = 	srcs/main.c \
		srcs/ptr_ft.c \
		srcs/ptr_ft1.c \
		srcs/ptr_ft2.c \
		srcs/ptr_ft3.c \
		srcs/ptr_ft4.c \
		srcs/ft_fractol.c \
		srcs/ft_fractol_bis.c \
		srcs/ft_display.c \
		srcs/ft_init_event.c

OBJ = $(SRCS:.c=.o)

$(NAME) : $(OBJ)
	@make -s -C libs/libft
	@echo "Libft Compiled"
	@make -s -C libs/minilibx_macos
	@echo "Minilibx Compiled"
	@$(CC) $(LIBS) -lft -lmlx -framework OpenGL -framework AppKit -o $@ $^
	@echo "fractol Compiled"

all : $(NAME)

%.o: %.c
	@$(CC) -o $@ -c $<

clean :
	@make clean -s -C libs/libft
	@echo ".o Libft delete"
	@make clean -s -C libs/minilibx_macos
	@echo ".o Minilibx delete"
	@$(RM) $(OBJ)
	@echo ".o fractol delete"

fclean : clean
	@$(RM) libs/libft/libft.a
	@echo "libft.a delete"
	@$(RM) libs/minilibx_macos/libmlx.a
	@echo "libmlx.a delete"
	@$(RM) $(NAME)
	@echo "fractol delete"

re : fclean all
