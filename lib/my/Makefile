##
## EPITECH PROJECT, 2017
## EvalExpr
## File description:
## Lib Makefile
##

NAME = my

PRINTF_FOLDER = print_f/

SRCS =	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_strlen.c \
	$(PRINTF_FOLDER)my_printf.c	\
	$(PRINTF_FOLDER)my_printf_params.c	\
	$(PRINTF_FOLDER)scan_printf.c	\
	$(PRINTF_FOLDER)disp_int_funct.c	\
	$(PRINTF_FOLDER)disp_conv_uint.c	\
	$(PRINTF_FOLDER)disp_str_funct.c	\
	$(PRINTF_FOLDER)errors.c	\
	my_showstr.c	\
	my_put_nbrbase.c	\
	my_getnbr.c	\
	indexof.c	\
	my_strdup.c	\
	get_digits.c

OBJS = $(SRCS:.c=.o)

INC = -I .

CC = gcc

CFLAGS = $(INC) -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rc lib$(NAME).a $(OBJS)
	cp my.h ../../include
	cp lib$(NAME).a ..

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f lib$(NAME).a
	rm -f ../../lib$(NAME).a
	rm -f ../lib$(NAME).a

re: fclean all

debug: CFLAGS += -g
debug: re