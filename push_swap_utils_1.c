/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:51:38 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/29 21:21:47 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	equal_check(t_node *a_node, int data)
{
	t_list	*tmp;

	if (a_node->size <= 1)
		return (1);
	tmp = a_node->head;
	while (tmp->next != a_node->head)
	{
		if (data == tmp->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
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
		tmp = ft_lstnew(ft_atoi(str[cnt]), is_zero(str[cnt]));
		if (!tmp || !equal_check(node, tmp->data))
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
	
	tmp = ft_lstnew(ft_atoi(av[ac]), is_zero(av[ac]));
	if (!tmp || !equal_check(node, tmp->data))
		return (0);
	ft_lstadd_back(node, tmp);
	return (1);
}

int	is_str_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	set_parsing(int ac, char **av, t_node *node)
{
	while (ac-- > 1)
	{
		if (av[ac][0] == '\0')
			return (-1);
		if (is_str_space(av[ac]))
			continue ;
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
