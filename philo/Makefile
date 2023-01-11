# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: franmart <franmart@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 08:35:59 by franmart          #+#    #+#              #
#    Updated: 2023/01/11 10:57:04 by franmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDES = -pthread
RM = rm -rf

SRC_DIR = src/
_SRC =	main.c\
		utils.c\
		parser.c\
		ft_itoa.c

SRC = ${addprefix ${SRC_DIR}, ${_SRC}}
OBJ = ${SRC:.c=.o}

${NAME}: ${OBJ}
	$(CC) $(OBJ) -o $(NAME) $(INCLUDES)
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