NAME = push_swap

SOURCE = bonus.c	prace_bonus.c	bonus_helper_bonus.c push_swap_bonus.h check1_bonus.c \
		putstr_bonus.c stack_oper_three_bonus.c ft_split_bonus.c stack_opperations_bonus.c get_next_line.c stack_opr_tow_bonus.c \
		get_next_line_utils.c  utils_bonus.c linkedlist_bonus.c

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