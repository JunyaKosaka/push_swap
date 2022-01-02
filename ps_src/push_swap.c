/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:35:28 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/03 01:46:23 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	compress_arr(int total_len, t_info *info)
{
	int	*sorted_arr;
	int	i;

	sorted_arr = ft_bubble_sort(total_len, info->arr);
	if (!sorted_arr)
		exit(free_all_info(info, TRUE));
	i = -1;
	while (++i < total_len)
		(info->arr)[i] = find_index(total_len, sorted_arr, (info->arr)[i]);
	free_int_arr(&sorted_arr);
}

int	push_swap(int argc, char *argv[])
{
	t_info	info;
	int		total_len;
	int		result;

	if (argc == 1)
		return (0);
	if (is_error(argc, argv))
		exit(error_handler());
	total_len = argc - 1;
	info.arr = convert_to_int(total_len, argv);
	if (!(info.arr))
		exit(error_handler());
	compress_arr(total_len, &info);
	init_stack(total_len, &info);
	if (is_sorted(total_len, info.arr))
		return (free_all_info(&info, FALSE));
	result = ps_sort(&info);
	info.ans = compress_ans(&info);
	show_ans(info.ans);
	free_all_info(&info, FALSE);
	if (result == -1)
		return (error_handler());
	return (0);
}
