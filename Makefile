SRCS	=	

OBJS	=	${SRCS:%.c=%.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	pipex

#rules    -------------------------------------------------------------    rules

all:		${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "\033[1;32mcode compiled succesfully\033[0m"

clean:
	@rm -rf ${OBJS} ${NAME}.dSYM ${BOBJS} test
	@make -s -C ./lib/ft_printf clean
	@make -s -C ./lib/libft clean
	@echo "\033[1;31mobject files removed\033[0m"

fclean:		clean
	@rm -f ${NAME} generator bonus/checker
	@make -s -C ./lib/ft_printf fclean
	@make -s -C ./lib/libft fclean
	@echo "\033[1;33m${NAME} file removed\033[0m"

re:		fclean all

debug:	library
	@${CC} ${CFLAGS} ${LIB} ${SRCS} -o ${NAME}-debug -g

sanitize:	library
	@${CC} ${CFLAGS} ${LIB} ${SRCS} -o ${NAME}-sanitize -fsanitize=address

.PHONY:		all clean fclean re debug sanitize bonus
