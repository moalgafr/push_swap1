NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3
RM		=	rm	-rf

SRCS 	=	bitwise.c \
			checks.c \
			checks2.c \
			error.c \
			operation.c \
			operation1.c \
			operation2.c \
			push_swap.c \
			sort.c \
			sort1.c \
			sort2.c \
			tmp.c \
			utils.c \
			utils2.c \
			utils3.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY = all clean fclean re
