/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:39:07 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/02 22:03:57 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	cnt_ab1(int *a, int *b)
{
	int	cnt;

	cnt = 0;
	while (*a > 0 && *b > 0)
	{
		*a -= 1;
		*b -= 1;
		cnt++;
	}
	while (*a < 0 && *b < 0)
	{
		*a += 1;
		*b += 1;
		cnt++;
	}
	return (cnt);
}

int	cnt_ab2(int *a, int *b)
{
	int	cnt;

	cnt = 0;
	while (*a > 0)
	{
		*a -= 1;
		cnt++;
	}
	while (*a < 0)
	{
		*a += 1;
		cnt++;
	}
	while (*b > 0)
	{
		cnt++;
		*b -= 1;
	}
	while (*b < 0)
	{
		*b += 1;
		cnt++;
	}
	return (cnt);
}
