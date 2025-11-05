NAME = PmergeMe

SRC = main.cpp

OBJS = ${SRC:%.cpp=%.o}

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $@

%.o:%.cpp
	${CC} -c ${CFLAGS} $< -o $@

all: ${NAME}

debug: CFLAGS += -g -D DEBUG
debug: ${OBJS}
	${CC} ${CFLAGS}  ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
