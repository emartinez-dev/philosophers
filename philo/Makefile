# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 08:35:59 by franmart          #+#    #+#              #
#    Updated: 2023/01/21 18:12:01 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc -g3 #-fsanitize=thread
FLAGS = -Wall -Wextra -Werror #-lasan
INCLUDES = -pthread
RM = rm -rf

SRC_DIR = src/
_SRC =	main.c\
		parser.c\
		parsing_utils.c\
		parsing_utils2.c\
		philo_utils.c\
		routine.c\
		waiter.c\
		exit.c\
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