/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:08:20 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/02 21:12:03 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_node
{
	int				size;
	struct s_list	*head;
}	t_node;

int		ft_lstadd_back(t_node *node, t_list *new);
char	**freeall(char **strs);
int		is_zero(char *str);
t_node	*init_node(void);
void	print_error(int type);
void	do_op(char *str, t_node *a_node, t_node *b_node);
void	print_ko(void);
void	print_ok(void);
void	push_a_ext(t_node *a_node, t_list *top, t_list *tmp);
void	push_a(t_node *a_node, t_node *b_node, int flag);
void	push_b_ext(t_node *b_node, t_list *top, t_list *tmp);
void	push_b(t_node *a_node, t_node *b_node, int flag);
void	rev_rotate_a(t_node *node, int flag);
void	rev_rotate_b(t_node *node, int flag);
void	rev_rotate_r(t_node *a_node, t_node *b_node, int flag);
void	rotate_a(t_node *node, int flag);
void	rotate_b(t_node *node, int flag);
void	rotate_r(t_node *a_node, t_node *b_node, int flag);
void	swap_a(t_node *node, int flag);
void	swap_b(t_node *node, int flag);
void	swap_s(t_node *a_node, t_node *b_node, int flag);
int		is_str_space(char *str);
int		set_parsing(int ac, char **av, t_node *node);
int		equal_check(t_node *a_node, int data);
int		long_length_word(int ac, char **av, t_node *node);
int		is_sort(t_node *a_node);
int		checker(t_node *a_node, t_node *b_node);
int		one_length_word(int ac, char **av, t_node *node);
int		is_str_space(char *str);
int		set_parsing(int ac, char **av, t_node *node);
t_list	*ft_lstnew_zero(int data);
t_list	*ft_lstnew_node(int data);

#endif