/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:35:02 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/04 21:16:36 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_stack_sub(int total_len, t_info *info)
{
	info->a_size = total_len;
	info->b_size = 0;
	info->target = 0;
	info->total_len = total_len;
}

/*   value of sentinel is -1   */
void	init_stack(int total_len, t_info *info)
{
	t_dlst	*new;

	init_stack_sub(total_len, info);
	info->a = dlst_new(SENTINEL);
	info->b = dlst_new(SENTINEL);
	info->ans = dlst_new(SENTINEL);
	if (!(info->a) || !(info->b) || !(info->ans))
		exit(free_all_info(info, TRUE));
	while (total_len--)
	{
		new = dlst_new(*(info->arr + total_len));
		if (!new)
			exit(free_all_info(info, TRUE));
		dlst_pushback(&(info->a), new);
	}
}
