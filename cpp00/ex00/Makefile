NAME = megaphone


SRC = MegaPhone.cpp

OBJS = ${SRC:%.cpp=%.o}

CC = c++

CFLAGS = -g -Wall -Wextra -Werror -std=c++98

${NAME}: ${OBJS}
	${CC} ${OBJS} -o $@

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME} 

re: fclean all

.PHONY: all clean fclean re