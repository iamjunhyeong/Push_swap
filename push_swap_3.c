/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:44:19 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/29 14:47:02 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_rotate_r(t_node *a_node, t_node *b_node, int *a, int *b)
{
	while ((*a > 0) && (*b > 0))
	{
		rotate_r(a_node, b_node);
		*b = *b - 1;
		*a = *a - 1;
	}
	while ((*a < 0) && (*b < 0))
	{
		rev_rotate_r(a_node, b_node);
		*b = *b + 1;
		*a = *a + 1;
	}
}

void	apply_rotate_a(t_node *a_node, int a)
{
	while (a > 0)
	{
		rotate_a(a_node);
		a--;
	}
	while (a < 0)
	{
		rev_rotate_a(a_node);
		a++;
	}
}

void	apply_rotate_b(t_node *b_node, int b)
{
	while (b > 0)
	{
		rotate_b(b_node);
		b--;
	}
	while (b < 0)
	{
		rev_rotate_b(b_node);
		b++;
	}
}

void	two_list_sort(t_node *node)
{
	if (node->head->data < node->head->next->data)
		rotate_a(node);
}

void	three_list_sort(t_node *node)
{
	if (node->size == 1)
		return ;
	if (node->size == 2)
	{
		two_list_sort(node);
		return ;
	}
	if (node->head->next->data > node->head->prev->data)
	{
		if (node->head->data < node->head->next->data)
			rev_rotate_a(node);
	}
	else
	{
		if (node->head->data < node->head->prev->data)
			rotate_a(node);
	}
	if (node->head->prev->data > node->head->next->data)
		swap_a(node);
}
