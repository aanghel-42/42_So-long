# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 06:22:28 by aanghel           #+#    #+#              #
#    Updated: 2022/03/25 06:46:16 by aanghel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = ./src/*.c ./PRINTF/*.c

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

KIT = -l mlx -framework openGL -framework AppKit

$(NAME): $(SRCS)
		$(CC) $(FLAGS) $(SRCS) $(KIT) -o $(NAME)
			
all: $(NAME)

clean:
	rm $(NAME)
			
fclean:	clean
	rm -rf *.dSYM
		
norm:
	norminette -R $(SRCS)

re:	fclean all

.PHONY:	all clean fclean re