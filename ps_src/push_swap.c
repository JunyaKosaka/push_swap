/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:35:28 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/09 01:54:41 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	compress_arr(t_info *info)
{
	int	*sorted_arr;
	int	i;

	sorted_arr = ft_bubble_sort(info->total_len, info->arr);
	if (!sorted_arr)
		exit(free_all_info(info, true));
	i = -1;
	while (++i < info->total_len)
		info->arr[i] = find_index(info->total_len, sorted_arr, (info->arr)[i]);
	free_int_arr(&sorted_arr);
}

int	push_swap(int argc, char *argv[])
{
	t_info	info;

	if (argc == 1)
		return (0);
	if (is_error(argc, argv))
		exit(error_handler());
	info.total_len = argc - 1;
	info.arr = convert_to_int(info.total_len, argv);
	if (!(info.arr))
		exit(free_all_info(&info, true));
	compress_arr(&info);
	init_stack(&info);
	if (is_sorted(info.total_len, info.arr))
		return (free_all_info(&info, false));
	ps_sort(&info);
	info.ans = compress_ans(&info);
	show_ans(info.ans);
	free_all_info(&info, false);
	return (0);
}
