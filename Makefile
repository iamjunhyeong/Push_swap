# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 15:01:09 by junhyeop          #+#    #+#              #
#    Updated: 2024/02/02 22:12:00 by junhyeop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

SRC_DIR = ./src
CHECKER_DIR = ./check

SRC	= $(SRC_DIR)/push_swap_1.c \
		$(SRC_DIR)/push_swap_2.c \
		$(SRC_DIR)/push_swap_3.c \
		$(SRC_DIR)/push_swap_utils_1.c \
		$(SRC_DIR)/push_swap_utils_2.c \
		$(SRC_DIR)/push_swap_utils_3.c \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/push.c \
		$(SRC_DIR)/rev_rotate.c \
		$(SRC_DIR)/rotate.c \
		$(SRC_DIR)/swap.c 

SRC_BONUS = $(CHECKER_DIR)/checker_bonus.c \
		$(CHECKER_DIR)/checker_utils_bonus.c \
		$(CHECKER_DIR)/checker_do_op_1_bonus.c \
		$(CHECKER_DIR)/checker_do_op_2_bonus.c \
		$(CHECKER_DIR)/checker_do_op_3_bonus.c\
		$(CHECKER_DIR)/checker_prs_1_bonus.c \
		$(CHECKER_DIR)/checker_prs_2_bonus.c

LIBDIR = ./libft/
LIBNAME = ft
LIB = $(LIBDIR)lib$(LIBNAME).a
INCDIRS = ./inc/

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
	${RM} $(SRC_DIR)/*.o $(CHECKER_DIR)/*.o

fclean: clean
	$(MAKE) -C $(LIBDIR) fclean
	${RM} $(NAME) $(NAME_BONUS)

re: fclean bonus

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re bonus




