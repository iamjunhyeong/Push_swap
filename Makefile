# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 15:01:09 by junhyeop          #+#    #+#              #
#    Updated: 2024/02/02 20:32:59 by junhyeop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker



SRC	= push_swap_1.c \
		push_swap_2.c \
		push_swap_3.c \
		push_swap_utils_1.c \
		push_swap_utils_2.c \
		push_swap_utils_3.c \
		main.c \
		push.c \
		rev_rotate.c \
		rotate.c \
		swap.c 

SRC_BONUS = checker_bonus.c checker_utils_bonus.c checker_do_op_1_bonus.c \
		checker_do_op_2_bonus.c checker_do_op_3_bonus.c checker_prs_1_bonus.c checker_prs_2_bonus.c

LIBDIR = ./libft/
LIBNAME = ft
LIB = $(LIBDIR)lib$(LIBNAME).a
INCDIRS = ./

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

CC = cc
MAKE = make
RM = rm -f
CFLAGS = -Wall -Wextra -Werror $(foreach D, $(INCDIRS), -I$(D))
ARFLAGS = rs

all: $(NAME)

%.o: %.c $(foreach D, $(INCDIRS), $(D)*.h)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(LIB) $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBDIR) -l$(LIBNAME)

$(NAME_BONUS): $(NAME) $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) -L$(LIBDIR) -l$(LIBNAME)

$(LIB):
	$(MAKE) -C $(LIBDIR) all
	
clean:
	$(MAKE) -C $(LIBDIR) clean
	${RM} $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C $(LIBDIR) fclean
	${RM} $(NAME) $(NAME_BONUS) ${OBJS} $(OBJS_BONUS)

re: fclean bonus

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re bonus




