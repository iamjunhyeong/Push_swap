/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:51:38 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/31 19:57:22 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	equal_check(t_node *a_node, int data)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (a_node->size == 0)
		return (1);
	tmp = a_node->head->prev;
	while (i < a_node->size)
	{
		if (data == tmp->data)
			return (0);
		tmp = tmp->prev;
		i++;
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
		if (is_zero(str[cnt]))
			tmp = ft_lstnew_zero(ft_atoi(str[cnt]));
		else
			tmp = ft_lstnew_node(ft_atoi(str[cnt]));
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

	if (is_zero(av[ac]))
		tmp = ft_lstnew_zero(ft_atoi(av[ac]));
	else
		tmp = ft_lstnew_node(ft_atoi(av[ac]));
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
