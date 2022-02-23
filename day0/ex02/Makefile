FOLDER_SRCS			=

SRCS				= tests.cpp Account.cpp

OBJS				= ${SRCS:.cpp=.o}

INCLUDES			= Account.hpp

NAME				= account

CC					= clang++

CFLAGS				= -Wall -Wextra -Werror

all:		${NAME}

%.o:		%.cpp %.hpp
			${CC} ${CFLAGS} -o $@ -c $<

${NAME}:	${OBJS} ${INCLUDES}
				${CC} ${CFLAGS} -o ${NAME} ${OBJS} 
				@echo compilation complete !

clean:
			@rm -f *.o 
			@echo files cleaned !

fclean:		clean
			@rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re