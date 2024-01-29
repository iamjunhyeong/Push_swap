/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:41:30 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/29 18:03:30 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_top(t_node *a_node, int *ind)
{
	t_list	*tmp;
	int		min;
	int		i;

	i = 0;
	tmp = a_node->head->prev;
	min = tmp->data;
	while (i++ < a_node->size)
	{
		if (min > tmp->data)
		{
			min = tmp->data;
			*ind = i - 1;
		}
		tmp = tmp->prev;
	}
	i = 0;
	while (i++ < *ind)
		tmp = tmp->prev;
	return (tmp);
}

int	location_cmp(int ab, int lab)
{
	int	cnt;
	int lcnt;

	cnt = 0;
	lcnt = 0;
	while (ab)
	{
		if (ab < 0)
			ab++;
		else
			ab--;
		cnt++;
	}
	while (lab)
	{
		if (lab < 0)
			lab++;
		else
			lab--;
		lcnt++;
	}
	if (cnt > lcnt)
		return (1);
	return (0);
}

void	find_pibot(t_node *a_node, int *pibot)
{
	t_list	*tmp;

	tmp = a_node->head;
	if (tmp->data > tmp->prev->data)
	{
		pibot[0] = tmp->data;
		pibot[1] = tmp->prev->data;
	}
	else
	{
		pibot[0] = tmp->prev->data;
		pibot[1] = tmp->data;
	}
}
void	divide_stack(t_node *a_node, t_node *b_node, int *pibot)
{
	t_list	*a_tmp;
	int		size;
	int		ind;

	ind = 0;
	size = a_node->size;
	a_tmp = a_node->head->prev;
	while (size--)
	{
		if (pibot[0] > a_tmp->data)
		{
			if (ind >= (a_node->size + 1) / 2)
				ind = a_node->size - ind;
			apply_rotate_a(a_node, ind);
			push_b(a_node, b_node);
			if (b_node->size >= 2 && pibot[1] > b_node->head->prev->data)
				rotate_b(b_node);
			ind = 0;
		}
		if (a_node->size == 5)
			break;
		a_tmp = a_tmp->prev;
		ind++;
	}
	while (a_node->size > 5)
		push_b(a_node, b_node);
	five_list_sort(a_node, b_node);
}
