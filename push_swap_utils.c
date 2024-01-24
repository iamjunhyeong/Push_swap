/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:51:38 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/24 22:37:22 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

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

void	swap_a(t_node *node)
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
	write(1, "sa\n", 3);
}

void	swap_b(t_node *node)
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
	write(1, "sb\n", 3);
}

void	swap_s(t_node *a_node, t_node *b_node)
{
	swap_a(a_node);
	swap_b(b_node);
	write(1, "ss\n", 3);
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
	write (1, "pa\n", 3);
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
	write (1, "pb\n", 3);
}

void	rotate_a(t_node *node)
{
	if (node->size >= 2)
	{
		node->head = node->head->prev;
		write (1, "ra\n", 3);
	}
}

void	rotate_b(t_node *node)
{
	if (node->size >= 2)
	{
		node->head = node->head->next;
		write (1, "rb\n", 3);
	}
}

void	rotate_r(t_node *a_node, t_node *b_node)
{
	if (a_node->size >= 2 && b_node->size >= 2)
	{
		a_node->head = a_node->head->prev;
		b_node->head = b_node->head->prev;
		write (1, "rr\n", 3);
	}
}

void	rev_rotate_a(t_node *node)
{
	if (node->size >= 2)
	{
		node->head = node->head->next;
		write (1, "rra\n", 3);
	}
}

void	rev_rotate_b(t_node *node)
{
	if (node->size >= 2)
	{
		node->head = node->head->next;
		write (1, "rrb\n", 3);
	}
}

void	rev_rotate_r(t_node *a_node, t_node *b_node)
{
	if (a_node->size >= 2 && b_node->size >= 2)
	{
		a_node->head = a_node->head->next;
		b_node->head = b_node->head->next;
		write (1, "rrr\n", 3);
	}
}
void	two_list_sort(t_node *node)
{
	if (node->head->data < node->head->next->data)
		rotate_a(node);
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
			rev_rotate_a(node);
	}
	else
	{
		if (node->head->data < node->head->prev->data)
			rotate_a(node);
	}
	if (node->head->prev->data > node->head->next->data)
		swap_a(node);
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
		swap_a(node);
	else if (tmp->prev->prev->data > a->prev->data)
	{
		rev_rotate_a(node);
		swap_a(node);
		rotate_a(node);
		rotate_a(node);
	}
	else
		rev_rotate_a(node);
}

void	b_find_location(t_node *node, t_list *b, t_list *tmp)
{
	b = node->head->prev;
	if (tmp->data > b->data)
		return ;
	b = b->prev;
	if (tmp->prev->data > b->data)
		swap_a(node);
	else if (tmp->prev->prev->data > b->data)
	{
		swap_a(node);
		rotate_a(node);
		swap_a(node);
		rev_rotate_a(node);
	}
	else if (tmp->prev->prev->prev->data > b->data)
	{
		rev_rotate_a(node);
		swap_a(node);
		rotate_a(node);
		rotate_a(node);
	}
	else
		rev_rotate_a(node);
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


	// t_list *tmp;
	// int		i;
	// int		j;
	// int		min;

	// printf("%d %d \n\n", fir ,sec);
	// i = 0;
	// j = 0;
	// min = 0;
	// tmp = a_node->head;
	// while (a_node->size > j++)
	// {
	// 	if (tmp->data > min)
	// 	{
	// 		min = tmp->data;
	// 		i++;
	// 	}
	// 	if (i == fir)
	// 		pibot[0] = min;
	// 	if (i == sec)
	// 	{
	// 		pibot[1] = min;
	// 		break ;
	// 	}
	// 	tmp = tmp->next;
	// }
	// return (pibot);
}
void	divide_stack(t_node *a_node, t_node *b_node, int *pibot)
{
	t_list	*a_tmp;
	int		size;
	int		i;

	i = 0;
	size = a_node->size;
	a_tmp = a_node->head;
	while (i++ < size)
	{
		if (pibot[0] > a_tmp->data)
			push_B(a_node, b_node);
		else
			rotate_a(a_node);
		if (b_node->size >= 2 && pibot[1] > b_node->head->data)
			rotate_b(b_node);
		if (a_node->size == 3)
			break ;
	}
	while (a_node->size != 3)
		push_B(a_node, b_node);
	three_list_sort(a_node);
}

int	find_a_location(int top, t_node *a_node)
{
	t_list	*tmp;
	int		ind;
	int		mind;

	mind = 0;
	ind = 0;
	tmp = a_node->head->prev;
	while (mind < a_node->size)
	{
		if (tmp->prev->data < tmp->data)
		{
			ind = mind;
			break;
		}
		tmp = tmp->prev;
		mind++;
	}
	while (ind < a_node->size)
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

int	location_cmp(int a, int b, int a_l, int b_l)
{
	if (b < 0)
		b = -b;
	if (b_l < 0)
		b_l = -b_l;
	if (a + b > a_l + b_l)
		return (1);
	return (0);
}

void	minimum_rotate(t_node *a_node, t_node *b_node, int *a, int *b)
{
	t_list	*tmp;
	int		a_location;
	int		b_location;
	int		ind;
	int		top;

	ind = 0;
	tmp = b_node->head->prev;
	while (ind < b_node->size)
	{
		top = tmp->data;
		b_location = ind;
		a_location = find_a_location(top, a_node);
		if (ind >= (b_node->size + 1) / 2)
			b_location = (b_node->size - ind) * (-1);
		if (ind == 0 || location_cmp(*a, *b, a_location, b_location))
		{
			*a = a_location;
			*b = b_location;
		}
		tmp = tmp->prev;
		ind++;
	}
}
void	apply_rotate_r(t_node *a_node, t_node *b_node, int *a, int *b)
{
	while ((*a > 0) && (*b > 0))
	{
		rotate_r(a_node, b_node);
		*b = *b - 1;
		*a = *a - 1;
	}
	while ((*a < 0) && (*b < 0))
	{
		rev_rotate_r(a_node, b_node);
		*b = *b + 1;
		*a = *a + 1;
	}
}

void	apply_rotate_a(t_node *a_node, int a)
{
	while (a > 0)
	{
		rotate_a(a_node);
		a--;
	}
	while (a < 0)
	{
		rev_rotate_a(a_node);
		a++;
	}
}

void	apply_rotate_b(t_node *b_node, int b)
{
	while (b > 0)
	{
		rotate_b(b_node);
		b--;
	}
	while (b < 0)
	{
		rev_rotate_b(b_node);
		b++;
	}
}

int	find_list_min(t_node *a_node, int *min_ind)
{
	t_list	*tmp;
	int		min;

	tmp = a_node->head->prev;
	min = tmp->data;
	while (*min_ind < a_node->size)
	{
		tmp = tmp->prev;
		if (tmp->data < min)
			min = tmp->data;
		*min_ind = *min_ind + 1;
	}
	return (min);
}

void	sort_first(t_node *a_node)
{
	int	min;
	int	min_ind;

	min_ind = 0;
	min = find_list_min(a_node, &min_ind);
	if (min_ind >= (a_node->size + 1) / 2)
		min_ind = (a_node->size - min_ind) * (-1);
	while (min_ind)
	{
		if (min_ind > 0)
		{
			rotate_a(a_node);
			min_ind--;
		}
		else
		{
			rev_rotate_a(a_node);
			min_ind++;
		}
	}
}

void	sort(t_node *a_node, t_node *b_node)
{
	int		pibot[2];
	int		a;
	int		b;

	find_pibot(a_node, pibot);
	divide_stack(a_node, b_node, pibot);
	ft_lstprint(a_node);
	while (b_node->size)
	{
		a = 0;
		b = 0;
		minimum_rotate(a_node, b_node, &a, &b);
		apply_rotate_r(a_node, b_node, &a, &b);
		apply_rotate_a(a_node, a);
		apply_rotate_b(b_node, b);
		push_A(a_node, b_node);
		ft_lstprint(a_node);

	}
	sort_first(a_node);
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

	sort(a_node, b_node);
	ft_lstprint(a_node);
}
