/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:34:02 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/31 21:50:07 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_a_location(int top, t_node *a_node)
{
	t_list	*tmp;
	int		ind;
	int		i;

	ind = 0;
	i = 0;
	tmp = find_top(a_node, &ind);
	while (i++ < a_node->size)
	{
		if (top < tmp->data)
			break ;
		tmp = tmp->prev;
		ind++;
	}
	if (ind >= (a_node->size + 1) / 2)
		ind = (a_node->size - ind) * (-1);
	return (ind);
}

void	minimum_rotate(t_node *a_node, t_node *b_node, int *a, int *b)
{
	t_list	*b_tmp;
	int		a_location;
	int		b_location;
	int		ind;
	int		b_top;

	ind = 0;
	b_tmp = b_node->head->prev;
	while (ind < b_node->size)
	{
		b_top = b_tmp->data;
		a_location = find_a_location(b_top, a_node);
		b_location = ind;
		if (ind >= (b_node->size + 1) / 2)
			b_location = (b_node->size - ind) * (-1);
		if (ind == 0 || location_cmp(*a, *b, a_location, b_location))
		{
			*a = a_location;
			*b = b_location;
		}
		b_tmp = b_tmp->prev;
		ind++;
	}
}

int	find_list_min(t_node *a_node)
{
	t_list	*tmp;
	int		min_ind;
	int		min;
	int		i;

	i = 0;
	min_ind = 0;
	tmp = a_node->head->prev;
	min = tmp->data;
	while (i < a_node->size)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
			min_ind = i;
		}
		i++;
		tmp = tmp->prev;
	}
	return (min_ind);
}

void	sort_last(t_node *a_node)
{
	int	min_ind;

	min_ind = find_list_min(a_node);
	if (min_ind >= (a_node->size + 1) / 2)
		min_ind = (a_node->size - min_ind) * (-1);
	while (min_ind)
	{
		if (min_ind > 0)
		{
			rotate_a(a_node, 1);
			min_ind--;
		}
		else
		{
			rev_rotate_a(a_node, 1);
			min_ind++;
		}
	}
}

void	sort(t_node *a_node, t_node *b_node)
{
	int		pibot[2];
	int		a;
	int		b;

	find_pibot(a_node, pibot, a_node->size);
	divide_stack(a_node, b_node, pibot);
	while (b_node->size)
	{
		a = 0;
		b = 0;
		minimum_rotate(a_node, b_node, &a, &b);
		apply_rotate_r(a_node, b_node, &a, &b);
		apply_rotate_a(a_node, a);
		apply_rotate_b(b_node, b);
		push_a(a_node, b_node, 1);
	}
	sort_last(a_node);
}
