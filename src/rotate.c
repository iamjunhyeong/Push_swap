/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:24:13 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/02 22:04:06 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_a(t_node *node, int flag)
{
	if (node->size >= 2)
	{
		node->head = node->head->prev;
		if (flag)
			write (1, "ra\n", 3);
	}
}

void	rotate_b(t_node *node, int flag)
{
	if (node->size >= 2)
	{
		node->head = node->head->prev;
		if (flag)
			write (1, "rb\n", 3);
	}
}

void	rotate_r(t_node *a_node, t_node *b_node, int flag)
{
	if (a_node->size >= 2 && b_node->size >= 2)
	{
		a_node->head = a_node->head->prev;
		b_node->head = b_node->head->prev;
		if (flag)
			write (1, "rr\n", 3);
	}
}
