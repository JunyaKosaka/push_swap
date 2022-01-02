/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_ans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:55:16 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/02 18:28:22 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

static int	diff(int x, int y)
{
	if (x > y)
		return (x - y);
	else
		return (y - x);
}

static int	convert(int x, int y)
{
	return ((x + y + 1) / 2 + 1);
}

void	new_ans_addback(t_info *info, t_dlst **new_ans, int value)
{
	t_dlst	*d_new;

	d_new = dlst_new(value);
	if (!d_new)
		exit(free_all_info(info, TRUE));
	dlst_addback(new_ans, d_new);
}

static t_dlst	*compress_ans_one(t_info *info)
{
	int		new_value;
	t_dlst	*new_ans;
	t_dlst	*n_ptr;
	t_dlst	*old_ans;

	new_ans = NULL;
	new_ans_addback(info, &new_ans, SENTINEL);
	old_ans = info->ans->next;
	while (old_ans->value != SENTINEL)
	{
		n_ptr = old_ans->next;
		new_value = convert(old_ans->value, n_ptr->value);
		if (new_value % 3 == 0 && diff(old_ans->value, n_ptr->value) == 1)
		{
			if (new_value != PASS)
				new_ans_addback(info, &new_ans, new_value);
			old_ans = n_ptr;
		}
		else
			new_ans_addback(info, &new_ans, old_ans->value);
		old_ans = old_ans->next;
	}
	dlst_clear(&old_ans);
	return (new_ans);
}

t_dlst	*compress_ans(t_info *info)
{
	int	i;

	i = -1;
	while (++i < 5)
		info->ans = compress_ans_one(info);
	return (info->ans);
}