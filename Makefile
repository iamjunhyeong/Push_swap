NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar
ARFLAGS = -rcs
RM = rm
RMFLAGS = -f
INC = ./push_swap.h
SRCS = push_swap_1.c \
		push_swap_2.c \
		push_swap_3.c \
		push_swap_utils_1.c \
		push_swap_utils_2.c \
		ft_atoi.c \
		ft_split.c \
		main.c \
		push.c \
		rev_rotate.c \
		rotate.c \
		swap.c 

OBJS = $(SRCS:.c=.o)

%o : %c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(OBJS)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

bonus :
	make WITH_BONUS=1

.PHONY: all clean fclean re bonus