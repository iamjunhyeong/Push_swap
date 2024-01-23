/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:51:38 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/23 22:07:42 by junhyeop         ###   ########.fr       */
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
		tmp = tmp->prev;
		printf("%d\n", tmp->data);
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

// void	swap_b(t_node *node)
// {
// 	t_list	*a;
// 	t_list	*b;
	
// 	if (node == NULL || node->size == 1)
// 		return ;	
// 	a = node->head->prev;
// 	b = a->prev;

// 	if (node->size >= 3)
// 	{
// 		a->next->prev = b;
// 		b->prev->next = a;
// 	}
// 	a->prev = b->prev;
// 	a->next = b;
// 	b->next = node->head;
// 	b->prev = a;
// }

void	swap_s(t_node *a_node, t_node *b_node)
{
	swap(a_node);
	swap(b_node);
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
	a_node->size++;
}

void	push_B(t_node *a_node, t_node *b_node)
{
	t_list	*top;
	t_list	*tmp;
	
	if (a_node == NULL)
		return ;
	top = a_node->head->prev;
	top->prev->next = top->next;
	top->next->prev = top->prev;
	a_node->size--;
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
	b_node->size++;
}

void	rotate(t_node *node)
{
	if (node->size >= 2)
		node->head = node->head->prev;
}

// void	rotate_b(t_node *node)
// {
// 	if (node->size >= 2)
// 		node->head = node->head->next;
// }

void	rotate_r(t_node *a_node, t_node *b_node)
{
	if (a_node->size >= 2)
		a_node->head = a_node->head->prev;
	if (b_node->size >= 2)
		b_node->head = b_node->head->prev;
}

void	rev_rotate(t_node *node)
{
	if (node->size >= 2)
		node->head = node->head->next;
}

void	rev_rotate_r(t_node *a_node, t_node *b_node)
{
	if (a_node->size >= 2)
		a_node->head = a_node->head->next;
	if (b_node->size >= 2)
		b_node->head = b_node->head->next;
}
void	two_list_sort(t_node *node)
{
	if (node->head->data < node->head->next->data)
		rotate(node);
}


// void	push_B(t_node a_node, t_node b_node)
// {
	
// }
// void	A_to_B(t_node *a_node, t_node *b_node)
// {
// 	int pb;
// 	int i = a_node->size;
// 	int	top;

// 	pb = node->head->data;
// 	while (i--)
// 	{
// 		top = node->head;
// 		if (pb == top)
// 			swap_a(a_node);
// 		if (pb > top)
// 			pb(a_node, b_node);
// 	}
// 	write (1, "pb\n", 3);
// }

void	three_list_sort(t_node *node)
{
	if (node->head->next->data > node->head->prev->data)
	{
		if (node->head->data < node->head->next->data)
			rev_rotate(node);
	}
	else
	{
		if (node->head->data < node->head->prev->data)
			rotate(node);
	}
	if (node->head->prev->data > node->head->next->data)
		swap(node);
}

int	set_arr(int ac, char **av, t_node *node)
{
	t_list	*tmp;
	int		 cnt;
	// arr = (int *)malloc(sizeof(int) * ac);
	// if (!arr)
	// 	return (-1);
	cnt = 0;
	while (ac-- > 1)
	{
		tmp = ft_lstnew(ft_atoi(av[ac]));
		if (!tmp)
			return (-1);
		ft_lstadd_back(node, tmp);
		cnt++;
	}
	return (cnt);
}
void	a_find_location(t_node *node, t_list *a, t_list *tmp)
{
	a = node->head->prev;
	if (tmp->data > a->data)
		return ;
	a = a->prev;
	if (tmp->prev->data > a->data)
		swap(node);
	else if (tmp->prev->prev->data > a->prev->data)
	{
		rev_rotate(node);
		swap(node);
		rotate(node);
		rotate(node);
	}
	else
		rev_rotate(node);
}

void	b_find_location(t_node *node, t_list *b, t_list *tmp)
{
	b = node->head->prev;
	if (tmp->data > b->data)
		return ;
	b = b->prev;
	if (tmp->prev->data > b->data)
		swap(node);
	else if (tmp->prev->prev->data > b->data)
	{
		swap(node);
		rotate(node);
		swap(node);
		rev_rotate(node);
	}
	else if (tmp->prev->prev->prev->data > b->data)
	{
		rev_rotate(node);
		swap(node);
		rotate(node);
		rotate(node);
	}
	else
		rev_rotate(node);
}

void	five_list_sort(t_node *a_node, t_node *b_node)
{
	t_list	*tmp;

	push_B(a_node, b_node);
	push_B(a_node, b_node);
	three_list_sort(a_node);
	tmp = a_node->head->prev;
	push_A(a_node, b_node);
	a_find_location(a_node, a_node->head->prev, tmp);
	tmp = a_node->head->prev;
	push_A(a_node, b_node);
	b_find_location(a_node, a_node->head->prev, tmp);
}

int main(int argc, char **argv)
{
	t_node	*a_node;
	t_node	*b_node;
	int		arr_size;

	if (argc < 2)
		return (ERROR);
	a_node = init_node();
	b_node = init_node();
	
	arr_size = set_arr(argc, argv, a_node);
	if (arr_size == -1)
		return (ERROR);

	ft_lstprint(a_node);
	// push_B(a_node, b_node);
	five_list_sort(a_node, b_node);
	ft_lstprint(a_node);
	ft_lstprint(b_node);
}