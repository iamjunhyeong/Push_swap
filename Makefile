# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 15:01:09 by junhyeop          #+#    #+#              #
#    Updated: 2024/02/02 19:48:47 by junhyeop         ###   ########.fr        #
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

SRC_BONUS = checker_bonus.c checker_utils_bonus.c checker_do_op_1_bonus.c checker_do_op_2_bonus.c \
			checker_do_op_3_bonus.c checker_prs_1_bonus.c checker_prs_2_bonus.c

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = cc
MAKE = make
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
		MAKE -C ./libft
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

all:		$(NAME)

clean:
			make clean -C libft
			${RM} $(OBJ) $(OBJ_BONUS)

fclean: 	clean
			make fclean -C libft
			${RM} $(NAME) $(NAME_BONUS) ${OBJ} $(OBJ_BONUS)

re:			fclean bonus

bonus:		all $(OBJ_BONUS)
			$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT)


.PHONY:		all clean fclean re bonus




