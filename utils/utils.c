/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:59:38 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/01 22:39:00 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ft_swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int	find_index(int n, int *arr, int value)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		if (arr[i] == value)
			return (i);
	}
	return (-1);
}

int	is_in_border(int border[2], int x)
{
	return (border[0] <= x && x < border[1]);
}

int	is_sorted(int total_len, int *arr)
{
	int	i;

	i = 0;
	while (i < total_len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}








// // 削除用
// static void	compress_arr(int total_len, int **arr)
// {
// 	int	*sorted_arr;
// 	int	i;

// 	sorted_arr = ft_bubble_sort(total_len, *arr);
// 	if (!sorted_arr)
// 	{
// 		free_int_arr(arr);
// 		exit(error_handler());
// 	}
// 	i = -1;
// 	while (++i < total_len)
// 		(*arr)[i] = find_index(total_len, sorted_arr, (*arr)[i]);		
// 	free_int_arr(&sorted_arr);
// }
