NAME = test.out

SRC = main.cpp AAnimal.cpp Cat.cpp Dog.cpp Brain.cpp

OBJS = ${SRC:%.cpp=%.o}

CC = c++

CFLAGS = -g -Wall -Wextra -Werror -std=c++98

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $@

%.o:%.cpp
	${CC} -c ${CFLAGS} $< -o $@

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME} 

re: fclean all

.PHONY: all clean fclean re