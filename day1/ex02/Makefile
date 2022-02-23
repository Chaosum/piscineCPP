FOLDER_SRCS			=

SRCS				= main.cpp

OBJS				= ${SRCS:.cpp=.o}

INCLUDES			=

NAME				= brain

CC					= clang++

CFLAGS				= -Wall -Wextra -Werror

all:		${NAME}

%.o:		%.cpp %.hpp
			${CC} ${CFLAGS} -c $< -o $@

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