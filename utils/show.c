/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:52:51 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 17:53:30 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	show_one(t_dlst	*lst)
{
	t_dlst	*cur;

	cur = lst;
	cur = cur->prev;
	while (cur->value != -1)
	{
		printf("%d\n", cur->value);
		cur = cur->prev;
	}
}

void	show_ans(t_dlst	*lst)
{
	t_dlst	*cur;

	cur = lst;
	cur = cur->next;
	char	*s[] = {"", "sa", "sb", "ss", "pa", "pb", "pass", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	while (cur->value != -1)
	{
		ft_printf("%s\n", s[cur->value]);
		cur = cur->next;
	}
}

void	show(t_info *info)
{
	printf("== a ==\n");
	show_one(info->a);
	printf("== b ==\n");
	show_one(info->b);
	printf("====\n");
}
