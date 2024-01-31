/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:47:59 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/31 19:56:51 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstadd_back(t_node *node, t_list *new)
{
	t_list	*tmp;
	t_list	*pre;

	tmp = node->head;
	if (new == NULL)
		return (0);
	if (tmp == NULL)
		node->head = new;
	else if (tmp->prev == NULL)
	{
		tmp->prev = new;
		tmp->next = new;
		new->prev = tmp;
		new->next = tmp;
	}
	else
	{	
		pre = tmp->prev;
		tmp->prev = new;
		new->next = tmp;
		new->prev = pre;
		pre->next = new;
	}
	node->size++;
	return (1);
}

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

void	five_list_sort(t_node *a_node, t_node *b_node)
{
	int		top;
	int		a_location;
	int		i;

	i = 0;
	if (a_node->size <= 3)
		three_list_sort(a_node);
	else
	{	
		push_b(a_node, b_node);
		push_b(a_node, b_node);
		three_list_sort(a_node);
		while (i++ < 2)
		{
			top = b_node->head->prev->data;
			a_location = find_a_location(top, a_node);
			apply_rotate_a(a_node, a_location);
			push_a(a_node, b_node);
		}
		sort_last(a_node);
	}
}

int	is_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i++] != '0')
		return (0);
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
