/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:47:43 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 18:22:36 by jkosaka          ###   ########.fr       */
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

void	*free_int_arr(int **arr)
{
	if (arr)
	{
		free(*arr);
		*arr = NULL;
	}
	return (NULL);
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

int	push_swap(int argc, char *argv[])
{
	int	*arr;
	int	*sorted_arr;
	int	n;
	int	i;
	int	result;

	n = argc - 1;
	if (is_error(argc, argv))
		return (error_handler());
	if (argc == 1)
		return (0);
	arr = convert_to_int(n, argv);
	if (!arr)
		return (error_handler());
	sorted_arr = ft_bubble_sort(n, arr);
	if (!sorted_arr)
	{
		free_int_arr(&arr);
		return (error_handler());
	}
	i = -1;
	while (++i < n)
		arr[i] = find_index(n, sorted_arr, arr[i]);
	free_int_arr(&sorted_arr);
	result = solve(n, arr);
	if (result == -1)
		return (error_handler());
	free_int_arr(&arr);
	return (0);
}
