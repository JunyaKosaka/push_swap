/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:35:02 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/31 15:16:14 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_info	init_stack_sub(int total_len, int divide)
{
	t_info info;

	info.a_size = total_len;
	info.b_size = 0;
	info.target = 0;
	info.divide = divide;
	info.total_len = total_len;
	set_wall(&info);
	// int i = 0;
	// while (i <= info.divide)
	// {
	// 	printf("29 %d\n", info.wall[i]);
	// 	i++;
	// }
	return (info);
}

/*   value of sentinel is -1   */
t_info	init_stack(int total_len, int **arr, int divide)
{
	t_info	info;
	t_dlst	*new;

	info = init_stack_sub(total_len, divide);
	info.a = dlst_new(SENTINEL);
	info.b = dlst_new(SENTINEL);
	info.ans = dlst_new(SENTINEL);
	if (!(info.a) || !(info.b) || !(info.ans))
		exit(free_all_info(&info, arr, TRUE));
	while (total_len--)
	{
		new = dlst_new(*(*arr + total_len));
		if (!new)
			exit(free_all_info(&info, arr, TRUE));
		dlst_addback(&(info.a), new);
	}
	return (info);
}
