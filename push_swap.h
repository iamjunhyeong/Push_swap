/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:51:49 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/28 14:54:42 by junhyeop         ###   ########.fr       */
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

char	**ft_split(char const *s, char c, int *cnt);
int		ft_atoi(const char *str);
char	**freeall(char **strs);
size_t	ft_strlen(const char *s);

#endif