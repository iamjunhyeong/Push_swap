NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar
MAKE = make
ARFLAGS = -rcs

RM = rm
RMFLAGS = -f

INCDIRS = ./
INC = ./push_swap.h

LIBDIR = ./libft/
LIBNAME = ft
LIB = $(LIBDIR)lib$(LIBNAME).a

SRCS = push_swap_1.c \
		push_swap_2.c \
		push_swap_3.c \
		push_swap_utils_1.c \
		push_swap_utils_2.c \
		main.c \
		push.c \
		rev_rotate.c \
		rotate.c \
		swap.c 

SRCS_CHECKER = checker.c

OBJS = $(SRCS:.c=.o)

ifdef WITH_BONUS
	NAME := $(CHKER_NAME)
endif

%o : %c ($(foreach D, $(INCDIRS), $(D)*.h))
	$(CC) $(CFLAGS) -c -o $@ $<

$(CHKER_NAME) : 

$(NAME) : $(OBJS) $(LIB)
	$(CC) -o $(NAME) $(OBJS) -L$(LIBDIR) -l$(LIBNAME)

$(LIB):
	$(MAKE) -C $(LIBDIR) all

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(OBJS)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
	$(MAKE) -C $(LIBDIR) fclean

re: fclean all

bonus :
	make WITH_BONUS=1

.PHONY: all clean fclean re bonus