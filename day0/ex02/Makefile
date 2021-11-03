FOLDER_SRCS			=

SRCS				= tests.cpp Account.cpp

OBJS				= ${SRCS:.c=.o}

INCLUDES			= Account.hpp

NAME				= account

CC					= clang++

CFLAGS				= -Wall -Wextra -Werror

all:		${NAME}

%.o:		%.c
			${CC} ${CFLAGS} -o $@ -c $<

${NAME}:	${OBJS}
				${CC} ${CFLAGS} -o ${NAME} ${OBJS} 
				@echo compilation complete !
			

${OBJS}:	${INCLUDES}

clean:
			@rm -f *.o 
			@echo files cleaned !

fclean:		clean
			@rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re