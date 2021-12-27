/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_ans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:55:16 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 19:46:20 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	ft_dlst_addback(&new_ans, ft_dlst_new(-1));
	ans = ans->next;
	while (ans->value != -1)
	{
		next = ans->next;
		new_value = convert(ans->value, next->value);
		if (new_value % 3 == 0 && diff(ans->value, next->value) == 1)
		{
			if (new_value != PASS)
				ft_dlst_addback(&new_ans, ft_dlst_new(new_value));
			ans = next->next;
		}		
		else
		{
			ft_dlst_addback(&new_ans, ft_dlst_new(ans->value));
			ans = next;
		}
	}
	while (ans->value != -1)
		ans = ans->next;
	ft_dlst_clear(&ans);
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
