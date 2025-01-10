NAME = push_swap
SOURCE = ft_split.c get_next_line.c get_next_line_utils.c insertion_sort.c \
		insertion_sort_helper.c linkedlist.c push_swap.c putstr.c sort_big_stack.c stack_oper_three.c \
		stack_opperations.c stack_opr_tow.c utils.c
CC=cc
CFLAGS=-Wall -Werror -Wextra
HEADER=push_swap.h
OBJF=${SOURCE: .c = .o}

all:${NAME}

NAME:${SOURCE}
	${CC} ${CFLAGS} $^