SRCS				= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJS				= ${SRCS:.cpp=.o}

INCLUDES			= ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

NAME				= DiamondTrap

CC					= c++

CFLAGS				= -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

all:		${NAME}

%.o:		%.cpp
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