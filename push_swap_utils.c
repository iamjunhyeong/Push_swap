/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:51:38 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/28 17:25:33 by junhyeop         ###   ########.fr       */
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
	if (node->size == 1)
		return ;
	if (node->size == 2)
	{
		two_list_sort(node);
		return ;
	}
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

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != 0)
		n++;
	return ((size_t)n);
}

int	long_length_word(int ac, char **av, t_node *node)
{
	t_list	*tmp;
	char	**str;
	int		cnt;
	
	cnt = 0;
	str = ft_split(av[ac], ' ', &cnt);
	while (cnt--)
	{
		tmp = ft_lstnew(ft_atoi(str[cnt]));
		if (!tmp)
		{
			str = freeall(str);
			return (0);
		}
		ft_lstadd_back(node, tmp);
		if (node->size == 2147483647)
			return (node->size);
	}
	str = freeall(str);
	return (1);
}

int	one_length_word(int ac, char **av, t_node *node)
{
	t_list	*tmp;

	tmp = ft_lstnew(ft_atoi(av[ac]));
	if (!tmp)
		return (0);
	ft_lstadd_back(node, tmp);
	return (1);
}

int	set_arr(int ac, char **av, t_node *node)
{
	while (ac-- > 1)
	{
		if (ft_strlen(av[ac]) > 1)
		{
			if (!long_length_word(ac, av, node))
				return (-1);
		}
		else
		{
			if (!one_length_word(ac, av, node))
				return (-1);
		}
		if (node->size == 2147483647)
			return (node->size);
	}
	return (node->size);
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



// int check_location(t_node *a_node, t_list *tmp, int top)
// {
// 	t_list	*tmp;
// 	int		i;

// 	i = 0;
// 	head = a_node->head;
// 	if (top < tmp->data && top > tmp->prev->data)
// 	{
		
// 	}
// }

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

int	find_a_location(int top, t_node *a_node)
{
	t_list	*tmp;
	int		ind;
	int		i;
	
	ind = 0;
	i = 0;
	tmp = find_top(a_node, &ind);
	while (i++ < a_node->size)
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

void	minimum_rotate(t_node *a_node, t_node *b_node, int *a, int *b)
{
	t_list	*b_tmp;
	int		a_location;
	int		b_location;
	int		ind;
	int		b_top;

	ind = 0;
	b_tmp = b_node->head->prev;
	while (ind < b_node->size)
	{
		b_top = b_tmp->data;
		b_location = ind;
		a_location = find_a_location(b_top, a_node);
		if (ind >= (b_node->size + 1) / 2)
			b_location = (b_node->size - ind) * (-1);

		if (ind == 0 || location_cmp(*a - *b, a_location - b_location))
		{
			*a = a_location;
			*b = b_location;
		}
		b_tmp = b_tmp->prev;
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

int	find_list_min(t_node *a_node)
{
	t_list	*tmp;
	int		min_ind;
	int		min;
	int		i;

	i = 0;
	min_ind = 0;
	tmp = a_node->head->prev;
	min = tmp->data;
	while (i < a_node->size)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
			min_ind = i;
		}
		i++;
		tmp = tmp->prev;
	}
	return (min_ind);
}

void	sort_last(t_node *a_node)
{
	int	min_ind;

	min_ind = find_list_min(a_node);
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
	while (b_node->size)
	{
		a = 0;
		b = 0;
		minimum_rotate(a_node, b_node, &a, &b);
		apply_rotate_r(a_node, b_node, &a, &b);
		apply_rotate_a(a_node, a);
		apply_rotate_b(b_node, b);
		push_A(a_node, b_node);
	}
	sort_last(a_node);
}
int print_error(int type)
{
	if (type >= 1)
		write(1, "ERROR\n", 6);
	exit(1);
	return (-1);
}

int is_cur_sort(t_node *a_node)
{
	t_list *tmp;

	tmp = a_node->head;
	while (tmp->next != a_node->head)
	{
		if (tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
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
		printf("%d\n", tmp->data);
		rmv = tmp;
		tmp = tmp->next;
		free(rmv);
	}
	printf("b : %d\n",b_node->size);
	free(a_node);
	free(b_node);
}

int main(int argc, char **argv)
{
	t_node	*a_node;
	t_node	*b_node;

	if (argc < 2)
		print_error(1);
	a_node = init_node();
	b_node = init_node();
	if (!a_node || !b_node)
		print_error(1);
	if (set_arr(argc, argv, a_node) == -1)
		print_error(1);
	if (a_node->size <= 3)
		three_list_sort(a_node);
	else if (is_cur_sort(a_node))
		printf("sorting\n");
	else
		sort(a_node, b_node);
	ft_lstprint(a_node);
	free_node(a_node, b_node);
	system("leaks a.out"); 
}
