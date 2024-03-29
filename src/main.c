/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:11:24 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/02 22:03:35 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*init_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->size = 0;
	node->head = NULL;
	return (node);
}

void	print_error(int type)
{
	if (type >= 1)
		write(1, "Error\n", 6);
	exit(1);
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

void	free_node(t_node *a_node, t_node *b_node)
{
	t_list	*tmp;
	t_list	*rmv;
	int		i;

	i = a_node->size;
	tmp = a_node->head;
	while (i--)
	{
		rmv = tmp;
		tmp = tmp->next;
		free(rmv);
	}
	free(a_node);
	free(b_node);
}

int	main(int argc, char **argv)
{
	t_node	*a_node;
	t_node	*b_node;

	if (argc < 2)
		return (0);
	a_node = init_node();
	b_node = init_node();
	if (!a_node || !b_node)
		print_error(1);
	if (set_parsing(argc, argv, a_node) <= 0)
		print_error(1);
	if (is_sort(a_node))
		exit(1);
	else if (a_node->size <= 5)
		five_list_sort(a_node, b_node);
	else
		sort(a_node, b_node);
	free_node(a_node, b_node);
	return (0);
}
