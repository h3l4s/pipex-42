NAME    = pipex

SRCS    =   ./main.c ./ft_split.c ./utils.c ./utils2.c ./utils3.c ./utils4.c

GCC        = gcc

CFLAGS    = -Wall -Wextra -Werror

OBJS    = ${SRCS:.c=.o}

RM        = rm -rf

.c.o:
		${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${GCC} ${OBJS} -o ${NAME}

all:    ${NAME}

clean:
	${RM} ${OBJS}

fclean:    clean
		${RM} ${NAME}

re:        fclean all

.PHONY: bonus re clean fclean all
