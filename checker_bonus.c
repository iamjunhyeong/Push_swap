/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:33:14 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/02 19:41:14 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	checker(t_node *a_node, t_node *b_node)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (ft_strncmp(str, "Error\n", ft_strlen(str)) == 0)
			print_ko();
		do_op(str, a_node, b_node);
		free(str);
	}
	if (is_sort(a_node))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*a_node;
	t_node	*b_node;

	a_node = init_node();
	b_node = init_node();
	if (set_parsing(argc, argv, a_node) <= 0)
		print_error(1);
	if (is_sort(a_node) || checker(a_node, b_node))
		print_ok();
	else
		print_ko();
	return (0);
}
