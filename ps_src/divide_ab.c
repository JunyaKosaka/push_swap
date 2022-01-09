/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 01:00:59 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/09 11:02:06 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	divide_a_to_b(int len, t_info *info)
{
	int	i;
	int	inside_border_size;

	i = 0;
	inside_border_size = info->border_a[1] - info->border_a[0];
	while (i < len)
	{
		if (info->a_size == inside_border_size)
			return ;
		if (is_in_border(info->border_a, dlst_back(info->a)))
			ra(info);
		else
		{
			pb(info);
			if (is_in_border(info->border_b, dlst_back(info->b)))
				rb(info);
		}
		i++;
	}
}

void	divide_b_to_a(int len, t_info *info)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (is_in_border(info->border_b, dlst_back(info->b)))
			rb(info);
		else if (i < len - 3 && check_b_four(info))
		{
			pa(info);
			pa(info);
			ra(info);
			ra(info);
			i++;
		}
		else
		{
			pa(info);
			if (is_in_border(info->border_a, dlst_back(info->a)))
				ra(info);
		}
		i++;
	}
}
