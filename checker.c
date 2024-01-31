/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:33:14 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/31 22:19:20 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define BUFFER_SIZE 100

void	print_ok()
{
	write(1, "OK\n", 3);
	exit(1);
}

void	print_ko()
{
	write(1, "KO\n", 3);
	exit(1);
}
int	checker(t_node *a_node, t_node *b_node)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (ft_strcmp(str, "Error\n") == 0)
			print_ko();
		do_op(str, a_node, b_node);
		free(str);
	}
	if (is_sort(a_node))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*a_node;
	t_node	*b_node;

	a_node = init_node();
	b_node = init_node();
	
	if (set_parsing(argc, argv, a_node) <= 0)
		print_error(1);
	if (checker(a_node, b_node))
		print_ok();
	else
		print_ko();
	return (0);
}
void	do_op(char *str, t_node *a_node, t_node *b_node)
{
	if (ft_strcmp(str, "pa\n") == 0)
		push_a(a_node, b_node, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		push_b(a_node, b_node, 0);
	else if (ft_strcmp(str, "ra\n") == 0)
		rotate_a(a_node, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate_b(b_node, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		rotate_r(a_node, b_node, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		rev_rotate_a(a_node, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rev_rotate_b(b_node, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rev_rotate_r(a_node, b_node, 0);
	else if (ft_strcmp(str, "sa\n") == 0)
		swap_a(a_node, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		swap_b(b_node, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		swap_s(a_node, b_node, 0);
}

// void	checker(t_stack *a, t_stack *b)
// {
// 	char	*line;

// 	line = NULL;
// 	while (get_next_line(0, &line) > 0)
// 	{
// 		do_op(a, b, (const char *)line, 0);
// 		free(line);
// 	}
// 	free(line);
// 	if (is_sorted(a) && !b->top)
// 		write(1, "OK\n", 3);
// 	else
// 		write(1, "KO\n", 3);
// }

// int	main(int argc, char **argv)
// {
// 	t_stack	a;
// 	t_stack	b;
// 	int		i;

// 	init_stack(&a);
// 	init_stack(&b);
// 	i = 0;
// 	while (++i < argc)
// 	{
// 		if (!*argv[i])
// 			handle_error();
// 		while (*argv[i])
// 			argv[i] = get_values(&a, argv[i]);
// 	}
// 	checker(&a, &b);
// 	return (0);
// }