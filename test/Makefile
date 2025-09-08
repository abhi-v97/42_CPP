NAME = test.out

SRC = main.cpp array_bag.cpp searchable_array_bag.cpp tree_bag.cpp searchable_tree_bag.cpp set.cpp

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