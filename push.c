/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:26:15 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/31 21:27:15 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_ext(t_node *a_node, t_list *top, t_list *tmp)
{
	if (a_node->size == 0)
	{	
		a_node->head = top;
		top->next = top;
		top->prev = top;
	}
	else if (a_node->size == 1)
	{
		a_node->head->next = top;
		a_node->head->prev = top;
		top->next = a_node->head;
		top->prev = a_node->head;
	}
	else if (a_node->size >= 2)
	{		
		tmp = a_node->head->prev;
		tmp->next = top;
		a_node->head->prev = top;
		top->next = a_node->head;
		top->prev = tmp;
	}
}

void	push_a(t_node *a_node, t_node *b_node, int flag)
{
	t_list	*top;
	t_list	*tmp;

	tmp = NULL;
	if (b_node == NULL)
		return ;
	top = b_node->head->prev;
	top->prev->next = top->next;
	top->next->prev = top->prev;
	b_node->size--;
	push_a_ext(a_node, top, tmp);
	a_node->size++;
	if (flag)
		write (1, "pa\n", 3);
}

void	push_b_ext(t_node *b_node, t_list *top, t_list *tmp)
{
	if (b_node->size == 0)
	{
		b_node->head = top;
		top->next = top;
		top->prev = top;
	}
	else if (b_node->size == 1)
	{
		b_node->head->next = top;
		b_node->head->prev = top;
		top->next = b_node->head;
		top->prev = b_node->head;
	}
	else if (b_node->size >= 2)
	{		
		tmp = b_node->head->prev;
		tmp->next = top;
		b_node->head->prev = top;
		top->next = b_node->head;
		top->prev = tmp;
	}
}

void	push_b(t_node *a_node, t_node *b_node, int flag)
{
	t_list	*top;
	t_list	*tmp;

	tmp = NULL;
	if (a_node == NULL)
		return ;
	top = a_node->head->prev;
	top->prev->next = top->next;
	top->next->prev = top->prev;
	a_node->size--;
	push_b_ext(b_node, top, tmp);
	b_node->size++;
	if (flag)
		write (1, "pb\n", 3);
}
