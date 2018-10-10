# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/15 09:51:02 by maxisimo          #+#    #+#              #
#    Updated: 2018/05/15 12:16:21 by maxisimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF
SRC = calculs.c choose_color.c color.c display.c draw.c height.c hook.c main.c point.c initialization.c move.c parsing.c rotate.c utils.c zoom.c
LIB_H = -L libft -lft -I.
LIB = -Iminilibx_macos -Lminilibx_macos
FLAG = -lmlx -framework OpenGL -framework Appkit
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C minilibx_macos
	gcc -Wall -Wextra -Werror $(SRC) $(LIB_H) $(LIB) $(FLAG) -o $(NAME)

clean:
	make clean -C libft/
	make clean -C minilibx_macos/
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all
