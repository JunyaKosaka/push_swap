/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:47:43 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/26 19:42:38 by jkosaka          ###   ########.fr       */
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
			// atoiに失敗するかどうか
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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
	sorted_arr = ft_bubble_sort(n, arr);
	i = 0;
	while (i < n)
	{
		arr[i] = find_index(n, sorted_arr, arr[i]);
		i++;
	}
	free(sorted_arr);
	sorted_arr = NULL;
	i = 0;
	result = solve(n, arr);
	free(arr);
	arr = NULL;
	printf("arr_malloc_size is %zu\n", malloc_size(arr));
	return (0);
}
