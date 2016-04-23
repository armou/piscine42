# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoudin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/07 16:32:19 by aoudin            #+#    #+#              #
#    Updated: 2016/04/14 15:48:44 by aoudin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft.a

FLAG = -Wall -Wextra -Werror

HEADER = include/

OPTION = -c -I

OBJS = *.o

EXEC = ft_hexdump

SRCS = src/*.c

all: $(LIB)

$(LIB) :
	gcc $(FLAG) $(OPTION) $(HEADER) $(SRCS)
	ar rc $(LIB) $(OBJS)
	ranlib $(LIB)
	gcc -o $(EXEC) $(LIB)

clean :
	/bin/rm -f $(OBJS)

fclean : clean
	/bin/rm -f $(LIB) ./$(EXEC)

re : fclean all
