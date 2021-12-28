/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:47:43 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/28 20:24:47 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_error(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		if (ft_atoi(argv[i]) == LONG_MAX)
			return (1);
		i++;
	}
	return (0);
}

static int	*convert_to_int(int n, char *argv[])
{
	int	i;
	int	*ret;

	i = -1;
	ret = (int *)malloc(sizeof(int) * (n - 1));
	if (!ret)
		return (NULL);
	while (++i < n)
		ret[i] = ft_atoi(argv[i + 1]);
	return (ret);
}

static int	*compress_arr(int n, int *arr)
{
	int	*sorted_arr;
	int	i;

	sorted_arr = ft_bubble_sort(n, arr);
	if (!sorted_arr)
	{
		free_int_arr(&arr);
		error_handler();
		return (NULL);
	}
	i = -1;
	while (++i < n)
		arr[i] = find_index(n, sorted_arr, arr[i]);
	free_int_arr(&sorted_arr);
	return (arr);
}

int	solve(int total_len, int *arr)
{
	if (total_len < 300)
		return (solve_five(total_len, arr));
	else
		return (solve_quick_15(total_len, arr));
}

int	push_swap(int argc, char *argv[])
{
	int	*arr;
	int	total_len;
	int	result;

	total_len = argc - 1;
	if (is_error(argc, argv))
		return (error_handler());
	if (argc == 1)
		return (0);
	arr = convert_to_int(total_len, argv);
	if (!arr)
		return (error_handler());
	arr = compress_arr(total_len, arr);
	if (!arr)
		return (1);
	result = solve(total_len, arr);
	if (result == -1)
		return (error_handler());
	free_int_arr(&arr);
	return (0);
}
