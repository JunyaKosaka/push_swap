/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:05:43 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 18:07:19 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_a_to_b(int len, t_info *info, t_dlst **ans)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (isin(info->border_a, dlst_back(info->a)))
			ra(info, ans);
		else
		{
			pb(info, ans);
			if (isin(info->border_b, dlst_back(info->b)))
				rb(info, ans);
		}
		i++;
	}
}

void	divide_b_to_a(int len, t_info *info, t_dlst **ans)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (isin(info->border_b, dlst_back(info->b)))
			rb(info, ans);
		else
		{
			pa(info, ans);
			if (isin(info->border_a, dlst_back(info->a)))
				ra(info, ans);
		}
		i++;
	}
}
