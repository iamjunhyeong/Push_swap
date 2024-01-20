/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:51:38 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/21 02:18:26 by junhyeop         ###   ########.fr       */
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

void	ft_lstprint(t_node *lst)
{
	t_list	*tmp = lst->head;

	if (lst->size == 0)
		return ;
	do
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	} while (tmp && tmp != lst->head && lst->size > 1);
	printf("\n");
}

// void	ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	t_list	*tmp;

// 	if (!lst || !del)
// 		return ;
// 	while (*lst)
// 	{
// 		tmp = (*lst)->next;
// 		ft_lstdelone(*lst, del);
// 		*lst = tmp;
// 	}
// }

// void	ft_lstdelone(t_list *lst, void (*del)(void*))
// {
// 	if (!lst || !del)
// 		return ;
// 	del(lst->content);
// 	free(lst);
// }

t_list	*ft_lstnew(int data)
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

t_node	*init_node()
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->size = 0;
	node->head = NULL;
	return (node);
}

void	swap(t_node *node)
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
}
void	push_A(t_node *a_node, t_node *b_node)
{
	t_list	*top;
	t_list	*tmp;
	
	if (b_node == NULL)
		return ;
	top = b_node->head->prev;
	top->prev->next = top->next;
	top->next->prev = top->prev;
	b_node->size--;
	if (a_node->size == 0)
	{
		a_node->head = top;
		b_node = NULL;
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
	a_node->size++;
}

// void	push_B(t_node a_node, t_node b_node)
// {
	
// }

int main()
{
	t_node	*a_node;
	t_node	*b_node;

	a_node = init_node();
	b_node = init_node();
	ft_lstadd_back(a_node, ft_lstnew(1));
	ft_lstprint(a_node);
	ft_lstadd_back(a_node, ft_lstnew(2));
	ft_lstprint(a_node);
	ft_lstadd_back(a_node, ft_lstnew(3));
	ft_lstprint(a_node);
	ft_lstadd_back(a_node, ft_lstnew(4));
	ft_lstprint(a_node);
	push_A(b_node, a_node);
	swap(a_node);
	ft_lstprint(a_node);
	ft_lstprint(b_node);
}