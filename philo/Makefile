# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 08:35:59 by franmart          #+#    #+#              #
#    Updated: 2023/01/17 11:11:58 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc -g3
FLAGS = -Wall -Wextra -Werror
INCLUDES = -pthread
RM = rm -rf

SRC_DIR = src/
_SRC =	main.c\
		utils.c\
		parser.c\
		ft_itoa.c\
		routine.c\
		init.c

SRC = ${addprefix ${SRC_DIR}, ${_SRC}}
OBJ = ${SRC:.c=.o}

${NAME}: ${OBJ}
	$(CC) $(OBJ) -o $(NAME) $(INCLUDES) -g3
	@echo "$(NAME) compiled!"

%.o: %.c
	@${CC} ${FLAGS} -c $^ -o $@

all: ${NAME}

clean:
	@echo "Removing files..."
	@${RM} ${OBJ}
	@echo "Done!"

fclean: clean
	@${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re