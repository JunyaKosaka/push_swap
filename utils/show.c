/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:52:51 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/01 23:44:25 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	show_one(t_dlst	*lst)
{
	t_dlst	*cur;

	cur = lst;
	cur = cur->prev;
	while (cur->value != SENTINEL)
	{
		ft_putnbr_fd(cur->value, STDOUT);
		ft_putchar_fd('\n', STDOUT);
		cur = cur->prev;
	}
}

static char	*reply_ans(int x)
{
	if (x == 1)
		return ("sa");
	if (x == 2)
		return ("sb");
	if (x == 3)
		return ("ss");
	if (x == 4)
		return ("pa");
	if (x == 5)
		return ("pb");
	if (x == 6)
		return ("pass");
	if (x == 7)
		return ("ra");
	if (x == 8)
		return ("rb");
	if (x == 9)
		return ("rr");
	if (x == 10)
		return ("rra");
	if (x == 11)
		return ("rrb");
	return ("rrr");
}

void	show_ans(t_dlst	*lst)
{
	t_dlst	*cur;

	cur = lst;
	cur = cur->next;
	while (cur->value != SENTINEL)
	{
		ft_putendl_fd(reply_ans(cur->value), STDOUT);
		cur = cur->next;
	}
}

void	show(t_info info)
{
	ft_putendl_fd("== a ==", STDOUT);
	show_one(info.a);
	ft_putendl_fd("== b ==", STDOUT);
	show_one(info.b);
	ft_putendl_fd("====", STDOUT);
}
