# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhamid <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/21 15:52:41 by nhamid            #+#    #+#              #
#    Updated: 2019/08/08 17:54:02 by ymoukhli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
LIBFT = libft/libft.a
CFLAGS = gcc -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
P_SRC = stock_obj.c obj_check.c errors.c cam_check.c check_tools.c parse_file.c filereader.c light_check.c stock_scene.c
SRC = ft_free_obj.c ft_calcule.c ft_file2.c vectors.c ft_file0.c ft_file3.c ft_file7.c ft_file1.c ft_file8.c main.c ft_file9.c maping.c vect_check.c
PN_SRC = $(addprefix rt_parsing/,$(P_SRC))
DIR = rt_parsing

SRCO = $(SRC:.c=.o)
PRSO =  $(PN_SRC:.c=.o)
TMP = $(P_SRC:.c=.o)
OBJ = $(TMP) $(SRCO)

INC = -I libft/includes/ -I rt_parsing/ -I ./
INC_SRC = libft/includes/libft.h  rt_parsing/rtparse.h rtv1.h
all : $(NAME)

$(NAME) : $(SRCO) $(PRSO) $(LIBFT)
	$(CFLAGS) $(INC) -o $@ $(OBJ) $(LIBFT) $(MLX)

$(LIBFT) :
	make -C libft

$(PRSO) : %.o: %.c $(INC_SRC)
	$(CFLAGS) -c $< $(INC_SRC)

$(SRCO) : %.o: %.c $(INC_SRC)
	$(CFLAGS) -c $< $(INC)

clean :
	rm -rf $(OBJ)
	make -C libft clean

fclean : clean
	rm -rf $(NAME)
	make -C libft fclean

re : fclean all
