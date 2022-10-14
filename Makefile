# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmongell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 18:32:48 by tmongell          #+#    #+#              #
#    Updated: 2022/10/14 18:13:09 by tmongell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	error.c \
			initialisation.c \
			parsing.c \
			philo_actions.c \
			philosopher.c \
			threads_main_routine.c \
			utils.c \
			lib.c

OBJS	=	${SRCS:%.c=%.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror


NAME	=	philosopher

#rules    -------------------------------------------------------------    rules

all:		${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "\033[1;32m\ncode compiled succesfully\033[0m\n"

clean:
	@rm -rf ${OBJS} ${NAME}.dSYM ${BOBJS} test
	@echo "\033[1;31mobject files removed\033[0m"

fclean:		clean
	@rm -f ${NAME} generator bonus/checker
	@echo "\033[1;33m${NAME} file removed\033[0m"

re:		fclean all

debug:	library
	@${CC} ${CFLAGS} ${LIB} ${SRCS} -o ${NAME}-debug -g

sanitize:	library
	@${CC} ${CFLAGS} ${LIB} ${SRCS} -o ${NAME}-sanitize -fsanitize=address

strict:
	@${CC} ${CFLAGS} -D STRICT_SYNTAX -o ${NAME} ${SRCS}
	@echo "\033[1;32m\ncode compiled with output corresponding to the subject\033[0m\n"

.PHONY:		all clean fclean re debug sanitize bonus
