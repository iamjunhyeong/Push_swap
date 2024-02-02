/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:08:01 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/02 20:31:53 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	print_ok(void)
{
	write(1, "OK\n", 3);
	exit(1);
}

void	print_ko(void)
{
	write(1, "KO\n", 3);
	exit(1);
}

int	ft_lstadd_back(t_node *node, t_list *new)
{
	t_list	*tmp;
	t_list	*pre;

	tmp = node->head;
	if (new == NULL)
		return (0);
	if (tmp == NULL)
		node->head = new;
	else if (tmp->prev == NULL)
	{
		tmp->prev = new;
		tmp->next = new;
		new->prev = tmp;
		new->next = tmp;
	}
	else
	{	
		pre = tmp->prev;
		tmp->prev = new;
		new->next = tmp;
		new->prev = pre;
		pre->next = new;
	}
	node->size++;
	return (1);
}

void	do_op(char *str, t_node *a_node, t_node *b_node)
{
	if (ft_strncmp(str, "pa\n", ft_strlen(str)) == 0)
		push_a(a_node, b_node, 0);
	else if (ft_strncmp(str, "pb\n", ft_strlen(str)) == 0)
		push_b(a_node, b_node, 0);
	else if (ft_strncmp(str, "ra\n", ft_strlen(str)) == 0)
		rotate_a(a_node, 0);
	else if (ft_strncmp(str, "rb\n", ft_strlen(str)) == 0)
		rotate_b(b_node, 0);
	else if (ft_strncmp(str, "rr\n", ft_strlen(str)) == 0)
		rotate_r(a_node, b_node, 0);
	else if (ft_strncmp(str, "rra\n", ft_strlen(str)) == 0)
		rev_rotate_a(a_node, 0);
	else if (ft_strncmp(str, "rrb\n", ft_strlen(str)) == 0)
		rev_rotate_b(b_node, 0);
	else if (ft_strncmp(str, "rrr\n", ft_strlen(str)) == 0)
		rev_rotate_r(a_node, b_node, 0);
	else if (ft_strncmp(str, "sa\n", ft_strlen(str)) == 0)
		swap_a(a_node, 0);
	else if (ft_strncmp(str, "sb\n", ft_strlen(str)) == 0)
		swap_b(b_node, 0);
	else if (ft_strncmp(str, "ss\n", ft_strlen(str)) == 0)
		swap_s(a_node, b_node, 0);
	else
		print_error(1);
}

int	is_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i++] != '0')
		return (0);
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
