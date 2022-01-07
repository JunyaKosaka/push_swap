/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:35:02 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/08 03:09:34 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*   value of sentinel is -1   */
void	init_stack(t_info *info)
{
	t_dlst	*new;
	int		index;

	info->a_size = info->total_len;
	info->b_size = 0;
	info->target = 0;
	info->a = dlst_new(SENTINEL);
	info->b = dlst_new(SENTINEL);
	info->ans = dlst_new(SENTINEL);
	if (!(info->a) || !(info->b) || !(info->ans))
		exit(free_all_info(info, TRUE));
	index = info->total_len;
	while (index--)
	{
		new = dlst_new(*(info->arr + index));
		if (!new)
			exit(free_all_info(info, TRUE));
		dlst_pushback(&(info->a), new);
	}
}
