NAME = libftprintf.a

S_DIR = ./srcs

INCL = ./includes

SRCS =  $(S_DIR)/ft_atoi.c			$(S_DIR)/ft_strlen.c		$(S_DIR)/ft_itoa.c\
		$(S_DIR)/ft_madeall.c		$(S_DIR)/ft_printf.c		$(S_DIR)/ft_printspec.c\
		$(S_DIR)/ft_initstruct.c	$(S_DIR)/ft_readspec.c		$(S_DIR)/zeroflag.c\
		$(S_DIR)/minusflag.c		$(S_DIR)/width.c			$(S_DIR)/printsymb.c\
		$(S_DIR)/precision.c		$(S_DIR)/star.c				$(S_DIR)/printstring.c\
		$(S_DIR)/printaddress.c		$(S_DIR)/tosixtin.c			$(S_DIR)/print_space.c\
		$(S_DIR)/print_zero.c		$(S_DIR)/printnum.c			$(S_DIR)/print_zero_precision.c\
		$(S_DIR)/printnum.c			$(S_DIR)/printnum.c			$(S_DIR)/printpositive.c\
		$(S_DIR)/printnegative.c	$(S_DIR)/tosixteenlow.c		$(S_DIR)/printunsignednum.c\
		$(S_DIR)/printsixteen.c		$(S_DIR)/tosixteenhigh.c	$(S_DIR)/printother.c

OBJS = $(SRCS:.c=.o)

CC = gcc

RM = rm -f

HEADER = $(INCL)/ft_printf.h

CFLAGS = -Wall -Wextra -Werror

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

