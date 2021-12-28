/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:39:13 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/28 11:29:30 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	cal_last_sum(int len, t_dlst *a)
{
	long	sum;
	int		i;

	sum = 0;
	i = 0;
	a = a->prev;
	while (i < len)
	{
		sum += a->value;
		a = a->prev;
		i++;
	}
	return (sum);
}

int	ft_is_sorted(int n, int *arr)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

t_info	*init_stack(int total_len, int *arr, t_dlst **ans)
{
	t_info	*info;
	t_dlst	*new;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->a = ft_dlst_new(-1); // sentinel
	info->b = ft_dlst_new(-1);
	if (!(info->a) || !(info->b))
		return (NULL);
	info->total = total_len;
	info->target = 0;
	info->a_size = total_len;
	info->b_size = 0;
	info->b_sum = 0;
	while (total_len--)
	{
		new = ft_dlst_new(*(arr + total_len));
		if (!new)
			return (NULL);
		ft_dlst_addback(&(info->a), new);
	}
	*ans = ft_dlst_new(-1);
	if (!(*ans))
		return (NULL);
	return (info);
}
