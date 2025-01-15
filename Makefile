NAME = push_swap

SOURCE = ft_split.c helper_instra.c prace.c	putstr.c stack_oper_three.c \
		stack_opr_tow.c helper_instra2.c linkedlist.c push_swap.c \
		sort_big_stack.c  stack_opperations.c  utils.c

CC=cc

CFLAGS=-Wall -Werror -Wextra

HEADER=push_swap.h

OBJF=${SOURCE:.c=.o}

all:${NAME}

${NAME}:${OBJF}
	${CC} ${CFLAGS} $^ -o ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJF)

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean