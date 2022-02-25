SRCS				= main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp

OBJS				= ${SRCS:.cpp=.o}

INCLUDES			= AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp

NAME				= Materia

CC					= c++

CFLAGS				= -Wall -Wextra -Werror -std=c++98 #-g3 -fsanitize=address

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