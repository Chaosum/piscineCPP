FOLDER_SRCS			= srcs

SRCS				= ${addprefix ${FOLDER_SRCS}/, main.cpp Contact.cpp Phonebook.cpp}

OBJS				= ${SRCS:.cpp=.o}

INCLUDES			= ${addprefix ${FOLDER_SRCS}/, Phonebook.hpp Contact.hpp}

NAME				= phonebook

CC					= clang++

CFLAGS				= -Wall -Wextra -Werror

all:		${NAME}

%.o:		%.cpp
			${CC} ${CFLAGS} -o $@ -c $<

${NAME}:	${OBJS} ${INCLUDES}
				${CC} ${CFLAGS} -o ${NAME} ${OBJS} 
				@echo compilation complete !

clean:
			@rm -f *.o ${FOLDER_SRCS}/*.o
			@echo files cleaned !

fclean:		clean
			@rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re