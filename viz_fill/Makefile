# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/07 17:51:53 by lpohribn          #+#    #+#              #
#    Updated: 2018/09/07 17:51:57 by lpohribn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visualizer

SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIB_DIR = ../libft/
INC_DIR = ./inc/


SRC = main.c \
	ft_checking_line.c \
	ft_width.c \
	ft_error.c \
	ft_exit.c \
	ft_draw_map.c \
	ft_skip_else.c \
	ft_init_sdl.c \
	ft_draw_game.c \
	ft_event.c \
	ft_score.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

HEAD_VIS = $(INC_DIR)ft_visualization.h

HEAD_LIB = $(LIB_DIR)libft.h

HEAD_FLAGS = -I $(INC_DIR) -I $(LIB_DIR)

FLAGS = -Wall -Werror -Wextra

VIZFLAG_LIB = -L ~/.brew/lib/ -lSDL2 -lSDL2_TTF

VIZFLAG_INC = -I ~/.brew/include/

LIBFT_FLAGS =  -lft -L $(LIB_DIR)

LIBFT = $(LIB_DIR)libft.a

CC = gcc

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBFT_FLAGS) $(VIZFLAG_LIB)

$(LIBFT):
	@make -C $(LIB_DIR)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o : %.c $(HEAD_VIS) $(HEAD_LIB)
	$(CC) -c $< -o $@ $(FLAGS) $(HEAD_FLAGS) $(VIZFLAG_INC)

clean :
	make clean -C $(LIB_DIR)
	rm -rf $(OBJ)

fclean : clean
	make fclean -C $(LIB_DIR)
	rm -rf $(NAME)
	rm -rf $(OBJ_DIR)

re : fclean all

vpath %.c $(SRC_DIR)

.PHONY: $(LIBFT)
