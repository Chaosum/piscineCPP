SRCS				= main.cpp 

OBJS				= ${SRCS:.cpp=.o}

INCLUDES			= Array.hpp

NAME				= array

CC					= c++

CFLAGS				= -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

all:		${NAME}

%.o:		%.cpp ${INCLUDES}
			${CC} ${CFLAGS}  -o $@ -c $<

${NAME}:	${OBJS} 
				${CC} ${CFLAGS} -o ${NAME} ${OBJS} 
				@echo compilation complete !

clean:
			@rm -f *.o
			@echo files cleaned !

fclean:		clean
			@rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re