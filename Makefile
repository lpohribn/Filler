# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/31 18:37:52 by lpohribn          #+#    #+#              #
#    Updated: 2018/07/31 18:37:55 by lpohribn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lpohribn.filler

SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIB_DIR = ./libft/
VIZ_DIR = ./viz_fill/
INC_DIR = ./inc/


SRC = main.c \
		ft_map.c \
		ft_piece.c \
		ft_heatmap.c \
		ft_distance.c \
		ft_find_position.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

HEAD_FILLER = $(INC_DIR)filler.h

HEAD_LIB = $(LIB_DIR)libft.h

HEAD_FLAGS = -I $(INC_DIR) -I $(LIB_DIR)

FLAGS = -Wall -Werror -Wextra

LIBFT_FLAGS =  -lft -L $(LIB_DIR)

LIBFT = $(LIB_DIR)libft.a

CC = gcc

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBFT_FLAGS)

$(LIBFT):
	@make -C $(LIB_DIR)
	@make -C $(VIZ_DIR)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o : %.c $(HEAD_FILLER) $(HEAD_LIB)
	$(CC) -c $< -o $@ $(FLAGS) $(HEAD_FLAGS)

clean :
	make clean -C $(LIB_DIR)
	make clean -C $(VIZ_DIR)
	rm -rf $(OBJ)

fclean : clean
	make fclean -C $(LIB_DIR)
	make fclean -C $(VIZ_DIR)
	rm -rf $(NAME)
	rm -rf $(OBJ_DIR)

re : fclean all

vpath %.c $(SRC_DIR)

.PHONY: $(LIBFT)
