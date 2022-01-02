/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_ans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:55:16 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/02 17:44:39 by jkosaka          ###   ########.fr       */
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

static t_dlst	*compress_ans_one(t_dlst *ans)
{
	int		new_value;
	t_dlst	*new_ans;
	t_dlst	*next;

	new_ans = NULL;
	dlst_addback(&new_ans, dlst_new(-1));
	ans = ans->next;
	while (ans->value != SENTINEL)
	{
		next = ans->next;
		new_value = convert(ans->value, next->value);
		if (new_value % 3 == 0 && diff(ans->value, next->value) == 1)
		{
			if (new_value != PASS)
				dlst_addback(&new_ans, dlst_new(new_value)); // malloc失敗
			ans = next;
		}		
		else
			dlst_addback(&new_ans, dlst_new(ans->value));
		ans = ans->next;
	}
	while (ans->value != SENTINEL)
		ans = ans->next;
	dlst_clear(&ans);
	return (new_ans);
}

t_dlst	*compress_ans(t_dlst *ans)
{
	int		i;

	i = -1;
	while (++i < 5)
		ans = compress_ans_one(ans);
	return (ans);
}
