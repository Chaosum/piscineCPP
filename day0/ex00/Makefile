FOLDER_SRCS			= 

SRCS				= megaphone.cpp

OBJS				= ${SRCS:.cpp=.o}

INCLUDES			=

NAME				= megaphone

CC					= clang++

CFLAGS				= -Wall -Wextra -Werror

all:		${NAME}

%.o:		%.cpp
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