FOLDER_SRCS			= srcs

SRCS				= ${addprefix ${FOLDER_SRCS}/, magaphone.cpp}

OBJS				= ${SRCS:.cpp=.o}

INCLUDES			=

NAME				= magaphone

CC					= clang++

CFLAGS				= -Wall -Wextra -Werror

all:		${NAME}

%.o:		%.cpp %.hpp
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