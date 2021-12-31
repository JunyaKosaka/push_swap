/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:35:28 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/31 17:29:56 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_error(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (j == 0 && ft_strchr("-+", argv[i][j]))
				continue ;
			if (!ft_isdigit(argv[i][j]))
				return (1);
		}
		if (ft_atoi(argv[i]) == LONG_MAX)
			return (1);
		j = 0;
		while (++j < i)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
		}
	}
	return (0);
}

static int	*convert_to_int(int total_len, char *argv[])
{
	int	i;
	int	*ret;

	i = -1;
	ret = (int *)malloc(sizeof(int) * total_len);
	if (!ret)
		return (NULL);
	while (++i < total_len)
		ret[i] = ft_atoi(argv[i + 1]);
	return (ret);
}

static void	compress_arr(int total_len, int **arr)
{
	int	*sorted_arr;
	int	i;

	sorted_arr = ft_bubble_sort(total_len, *arr);
	if (!sorted_arr)
	{
		free_int_arr(arr);
		exit(error_handler());
	}
	i = -1;
	while (++i < total_len)
		(*arr)[i] = find_index(total_len, sorted_arr, (*arr)[i]);		
	free_int_arr(&sorted_arr);
}

int	push_swap(int argc, char *argv[])
{
	int	*arr;
	int	total_len;
	int	result;

	if (argc == 1)
		return (0);
	if (is_error(argc, argv))
		return (error_handler());
	total_len = argc - 1;
	arr = convert_to_int(total_len, argv);
	if (!arr)
		return (error_handler());
	if (is_sorted(total_len, arr))
	{
		free_int_arr(&arr);
		return (0);
	}
	compress_arr(total_len, &arr);
	result = ps_sort(total_len, &arr);

	free_int_arr(&arr);
	if (result == -1)
		return (error_handler());
	return (0);
}
