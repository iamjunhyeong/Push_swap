/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:41:30 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/31 21:28:21 by junhyeop         ###   ########.fr       */
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

int	cnt_ab1(int *a, int *b)
{
	int	cnt; 

	cnt = 0;
	while (*a > 0 && *b > 0)
	{
		*a -= 1;
		*b -= 1;
		cnt++;
	}
	while (*a < 0 && *b < 0)
	{
		*a += 1;
		*b += 1;
		cnt++;
	}
	return cnt;
}

int	cnt_ab2(int *a, int *b)
{
	int cnt;

	cnt = 0;
	while (*a > 0)
	{
		*a -= 1;
		cnt++;
	}
	while (*a < 0)
	{
		*a += 1;
		cnt++;
	}
	while (*b > 0)
	{
		cnt++;
		*b -= 1;
	}
	while (*b < 0)
	{
		*b += 1;
		cnt++;
	}
	return (cnt);
}

int	location_cmp(int a, int b, int al, int bl)
{
	int ab;
	int lab;

	ab = cnt_ab1(&a, &b) + cnt_ab2(&a, &b);
	lab = cnt_ab1(&al, &bl) + cnt_ab2(&al, &bl);
	if (ab > lab)
		return (1);
	return (0);
}

void	find_pibot(t_node *a_node, int *pibot, int size)
{
	t_list	*tmp;
	t_list	*t;
	int		n;
	int		m;
	int		ind;

	n = 0;
	tmp = a_node->head;
	while (n++ < size)
	{
		ind = 0;
		t = tmp;
		m = 0;
		while (m++ < size)
		{
			if (t->data <= tmp->data)
				ind++;
			t = t->next;
		}
		if (ind == (a_node->size + 1) / 3 * 2)
			pibot[0] = tmp->data;
		if (ind == (a_node->size + 1) / 3)
			pibot[1] = tmp->data;
		tmp = tmp->next;
	}
	// printf("\n0 1: %d  %d \n", pibot[0], pibot[1]);
	// exit(1);
}

int	get_a_location(int pibot, t_list *tmp, t_node *a_node)
{
	t_list	*tmp_nex;
	t_list	*tmp_prv;
	int		ind;
	int		i;

	// printf("pibot %d\n",pibot);
	// printf("top %d\n",tmp->data);
	if (tmp->data < pibot)
		return (0);
	tmp_nex = tmp->next;
	tmp_prv = tmp->prev;
	ind = 0;
	i = 1;
	while (i <= (a_node->size + 1) / 2)
	{
		if (pibot > tmp_nex->data)
			return (-i);
		if (pibot > tmp_prv->data)
			return (i);
		tmp_nex = tmp_nex->next;
		tmp_prv = tmp_prv->prev;
		i++;
	}
	return (0);
}

int	is_sort(t_node *a_node)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = a_node->head->prev;
	while (i < a_node->size)
	{
		if (tmp->data > tmp->prev->data)
			return (0);
		tmp = tmp->prev;
		i++;
	}
	return (1);
}

void	divide_stack(t_node *a_node, t_node *b_node, int *pibot)
{
	t_list	*a_tmp;
	t_list	*b_tmp;
	int		a_location;
	int		ind;

	ind = 0;
	while (a_node->size > 3)
	{
		if (is_sort(a_node))
			return ;
		a_tmp = a_node->head->prev;
		a_location = get_a_location(pibot[0], a_tmp, a_node);
		apply_rotate_a(a_node, a_location);
		push_b(a_node, b_node, 1);
		b_tmp = b_node->head->prev;
		if (b_node->size >= 2)
		{
			if (pibot[1] >= b_tmp->data && pibot[1] < b_tmp->prev->data)
				rotate_b(b_node, 1);
		}
	}
	while (a_node->size > 3)
		push_b(a_node, b_node, 1);
	three_list_sort(a_node);
}

// if (pibot[0] > a_tmp->data)
// 		{
// 			if (ind >= (a_node->size + 1) / 2)
// 				ind = a_node->size - ind;
// 			apply_rotate_a(a_node, ind);
// 			push_b(a_node, b_node);
// 			b_tmp = b_node->head->prev;
// 			if (b_node->size >= 2)
// 			{
// 				if (pibot[1] > b_tmp->data && pibot[1] < b_tmp->prev->data)
// 					rotate_b(b_node);
// 			}
// 			ind = 0;
// 		}
// 		else
// 			ind++;
// 		if (a_node->size == 5)
// 			break ;
// 		a_tmp = a_tmp->prev;