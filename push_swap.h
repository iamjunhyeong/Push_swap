/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:51:49 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/20 19:41:34 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list 
{
	int				data;
	sturct s_list	*next;
	sturct s_list	*prev;
}	t_list;

typedef struct s_init
{
	int				size;
	sturct s_list	*head;
}	t_init

#endif