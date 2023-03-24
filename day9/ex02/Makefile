SRCS				= main.cpp PmergeMe.cpp

OBJS				= ${SRCS:.cpp=.o}

INCLUDES			= PmergeMe.hpp

NAME				= PmergeMe

CC					= c++

CFLAGS				= -Wall -Wextra -Werror -std=c++98 #-g3 -fsanitize=undefined

all:		${NAME}

%.o:		%.cpp ${INCLUDES}
			${CC} ${CFLAGS} -c $< -o $@

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