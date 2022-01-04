/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_ans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:55:16 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/04 22:24:39 by jkosaka          ###   ########.fr       */
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

void	new_ans_pushback(t_info *info, t_dlst **new_ans, int value)
{
	t_dlst	*d_new;

	d_new = dlst_new(value);
	if (!d_new)
		exit(free_all_info(info, TRUE));
	dlst_pushback(new_ans, d_new);
}

static t_dlst	*compress_ans_one(t_info *info)
{
	int		new_value;
	t_dlst	*new_ans;
	t_dlst	*old_ans;

	new_ans = NULL;
	new_ans_pushback(info, &new_ans, SENTINEL);
	old_ans = info->ans->next;
	while (old_ans->value != SENTINEL)
	{
		new_value = convert(old_ans->value, old_ans->next->value);
		if (!(new_value % 3) && diff(old_ans->value, old_ans->next->value) == 1)
		{
			if (new_value != PASS)
				new_ans_pushback(info, &new_ans, new_value);
			old_ans = old_ans->next;
		}
		else if (old_ans->value == RB && old_ans->next->value == RRB)
			old_ans = old_ans->next;
		else if (old_ans->value == RRB && old_ans->next->value == RB)
			old_ans = old_ans->next;
		else if (old_ans->value == RA && old_ans->next->value == RRA)
			old_ans = old_ans->next;
		else
			new_ans_pushback(info, &new_ans, old_ans->value);
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
