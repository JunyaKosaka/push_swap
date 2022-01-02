/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:35:28 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/03 01:18:42 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	checker(int argc, char *argv[])
{
	t_info	info;
	int		total_len;
	int		result;

	if (argc == 1)
		return (0);
	if (is_error(argc, argv))
		exit(error_handler());
	total_len = argc - 1;
	result = 0;
	info.arr = convert_to_int(total_len, argv);
	// if (!(info.arr))
	// 	exit(error_handler());
	// compress_arr(total_len, &info);
	// init_stack(total_len, &info);
	// if (is_sorted(total_len, info.arr))
	// 	return (free_all_info(&info, FALSE));
	// result = ps_sort(&info);
	// info.ans = compress_ans(&info);
	// show_ans(info.ans);
	// free_all_info(&info, FALSE);
	// if (result == -1)
	// 	return (error_handler());
	return (0);
}
