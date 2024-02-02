/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:51:49 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/02 19:43:29 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

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

t_list	*ft_lstnew_node(int data);
t_list	*ft_lstnew_zero(int data);
t_list	*find_top(t_node *a_node, int *ind);
t_node	*init_node(void);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c, int *cnt);
char	**freeall(char **strs);
void	free_node(t_node *a_node, t_node *b_node);
void	minimum_rotate(t_node *a_node, t_node *b_node, int *a, int *b);
void	sort_last(t_node *a_node);
void	sort(t_node *a_node, t_node *b_node);
void	find_pibot(t_node *a_node, int *pibot, int size);
void	divide_stack(t_node *a_node, t_node *b_node, int *pibot);
void	apply_rotate_r(t_node *a_node, t_node *b_node, int *a, int *b);
void	apply_rotate_a(t_node *a_node, int a);
void	apply_rotate_b(t_node *b_node, int b);
void	two_list_sort(t_node *node);
void	three_list_sort(t_node *node);
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
void	five_list_sort(t_node *a_node, t_node *b_node);
void	b_find_location(t_node *node, t_list *b, t_list *tmp);
void	a_find_location(t_node *node, t_list *a, t_list *tmp);
void	print_error(int type);
int		ft_atoi(const char *str);
int		ft_lstadd_back(t_node *node, t_list *new);
int		find_a_location(int top, t_node *a_node);
int		find_list_min(t_node *a_node);
int		location_cmp(int a, int b, int al, int bl);
int		long_length_word(int ac, char **av, t_node *node);
int		get_a_location(int pibot, t_list *tmp, t_node *a_node);
int		one_length_word(int ac, char **av, t_node *node);
int		is_str_space(char *str);
int		set_parsing(int ac, char **av, t_node *node);
int		is_space(char c);
int		is_zero(char *str);
int		is_sort(t_node *a_node);

#endif