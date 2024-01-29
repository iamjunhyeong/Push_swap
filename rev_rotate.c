/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:25:39 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/29 18:01:31 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_node *node)
{
	if (node->size >= 2)
	{
		node->head = node->head->next;
		write (1, "rra\n", 4);
	}
}

void	rev_rotate_b(t_node *node)
{
	if (node->size >= 2)
	{
		node->head = node->head->next;
		write (1, "rrb\n", 4);
	}
}

void	rev_rotate_r(t_node *a_node, t_node *b_node)
{
	if (a_node->size >= 2 && b_node->size >= 2)
	{
		a_node->head = a_node->head->next;
		b_node->head = b_node->head->next;
		write (1, "rrr\n", 4);
	}
}
