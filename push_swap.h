/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:51:49 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/23 20:13:33 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERROR -1
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list 
{
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_node
{
	int				size;
	struct s_list	*head;
}	t_node;

char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);

#endif