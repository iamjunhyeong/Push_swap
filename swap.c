/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:47:19 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/29 18:01:30 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node *node)
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
	write(1, "sa\n", 3);
}

void	swap_b(t_node *node)
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
	write(1, "sb\n", 3);
}

void	swap_s(t_node *a_node, t_node *b_node)
{
	swap_a(a_node);
	swap_b(b_node);
	write(1, "ss\n", 3);
}
