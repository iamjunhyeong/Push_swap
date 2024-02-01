NAME = push_swap
NAME_BONUS = checker

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

SRCS_BONUS = checker.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

ifdef WITH_BONUS
	NAME := $(CHKER_NAME)
endif

%o : %c ($(foreach D, $(INCDIRS), $(D)*.h))
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS) $(LIB)
	$(CC) -o $(NAME) $(OBJS) -L$(LIBDIR) -l$(LIBNAME)

$(LIB):
	$(MAKE) -C $(LIBDIR) all

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) $(OBJS)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	$(RM) $(RMFLAGS) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBDIR) fclean

re: fclean bonus

bonus : all $(OBJ_BONUS)
        $(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT)

.PHONY: all clean fclean re bonus