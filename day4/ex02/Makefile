SRCS				= main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

OBJS				= ${SRCS:.cpp=.o}

INCLUDES			= Animal.hpp Cat.hpp Dog.hpp Brain.hpp

NAME				= Animal

CC					= c++

CFLAGS				= -Wall -Wextra -Werror -std=c++98 #-g3 -fsanitize=address

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