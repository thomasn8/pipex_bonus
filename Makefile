SRCS		= ${wildcard *.c}
OBJS		= ${SRCS:.c=.o}
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= pipex
RM			= rm -f

LIBFT_DIR	= libft
LIBFT_A		= libft.a
LIBFT		= -L./libft -lft

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make --silent -C ${LIBFT_DIR}/
			$(CC) $(CFLAGS) -o $(NAME) ${OBJS} $(LIBFT)

clean:
			${RM} ${OBJS}
			make --silent -C ${LIBFT_DIR} clean

fclean:		clean
			${RM} ${NAME}
			make --silent -C ${LIBFT_DIR} fclean

re:			fclean all

run:		
			./${NAME}

.PHONY:		all clean fclean re run
