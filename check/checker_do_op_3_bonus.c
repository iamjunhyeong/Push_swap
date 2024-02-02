/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_do_op_3_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:28:50 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/02 22:03:18 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

void	swap_a(t_node *node, int flag)
{
	t_list	*a;
	t_list	*b;

	if (node == NULL || node->size == 1)
		return ;
	a = node->head->prev;
	b = a->prev;
	if (node->size >= 3)
	{
		a->next->prev = b;
		b->prev->next = a;
	}
	a->prev = b->prev;
	a->next = b;
	b->next = node->head;
	b->prev = a;
	if (flag)
		write(1, "sa\n", 3);
}

void	swap_b(t_node *node, int flag)
{
	t_list	*a;
	t_list	*b;

	if (node == NULL || node->size == 1)
		return ;
	a = node->head->prev;
	b = a->prev;
	if (node->size >= 3)
	{
		a->next->prev = b;
		b->prev->next = a;
	}
	a->prev = b->prev;
	a->next = b;
	b->next = node->head;
	b->prev = a;
	if (flag)
		write(1, "sb\n", 3);
}

void	swap_s(t_node *a_node, t_node *b_node, int flag)
{
	swap_a(a_node, 0);
	swap_b(b_node, 0);
	if (flag)
		write(1, "ss\n", 3);
}
