
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =  command1.c command2.c command3.c ft_utils1.c ft_utils2.c \
		input1.c input2.c list.c list_cmd.c optimize.c \
		pre_sort1.c pre_sort2.c pre_sort3.c push_swap.c \
		sort1.c sort2.c sort_check_status.c sort_optimize.c sort_utils.c
OBJS = $(SRCS:.c=.o)
INC_DIR = ./includes
NAME = push_swap
RM = rm -rf

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $@ $^

.c.o	:
			$(CC) $(CFLAGS) -c $(SRCS) -I$(INC_DIR)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

bonus	:	re

.PHONY	:	all clean fclean re bonus
 