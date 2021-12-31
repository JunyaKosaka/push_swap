/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:05:43 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/31 15:15:33 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	divide_a_to_b(int len, t_info *info)
{
	int	i;

	i = 0;
	while (i < len)
	{
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
		else
		{
			pa(info);
			if (is_in_border(info->border_a, dlst_back(info->a)))
				ra(info);
		}
		i++;
	}
}
