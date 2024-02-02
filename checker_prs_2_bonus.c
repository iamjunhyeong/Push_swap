/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_prs_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:32:08 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/02 19:43:55 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_list	*ft_lstnew_zero(int data)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->prev = newnode;
	newnode->next = newnode;
	newnode->data = data;
	return (newnode);
}

t_list	*ft_lstnew_node(int data)
{
	t_list	*newnode;

	if (data == 0)
		return (NULL);
	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->prev = newnode;
	newnode->next = newnode;
	newnode->data = data;
	return (newnode);
}

int	is_sort(t_node *a_node)
{
	t_list	*tmp;
	int		i;

	i = 1;
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
