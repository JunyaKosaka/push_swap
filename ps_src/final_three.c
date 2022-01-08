/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:59:46 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/09 01:41:19 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	one_move(t_info *info)
{
	int	tail;
	int	a_last2;

	tail = info->total_len + 2;
	if (dlst_back(info->a) == tail)
		sa(info);
	else if (dlst_back(info->b) == tail)
	{
		ra(info);
		pa(info);
		sa(info);
		rra(info);
	}
	if (info->b_size)
		pa(info);
	a_last2 = dlst_rbegin(info->a)->prev->value;
	if (dlst_back(info->a) > a_last2)
		sa(info);
}

static void	zero_move(t_info *info)
{
	int	tail;
	int	a_last2;

	tail = info->total_len + 2;
	a_last2 = dlst_rbegin(info->a)->prev->value;
	if (dlst_back(info->a) == tail || a_last2 == tail)
	{
		pb(info);
		one_move(info);
	}
	else
	{
		if (dlst_back(info->a) > a_last2)
			sa(info);
	}
}

static void	two_move(t_info *info)
{
	int	tail;
	int	b_last2;

	tail = info->total_len + 2;
	b_last2 = dlst_rbegin(info->b)->prev->value;
	if (b_last2 == tail)
		rb(info);
	pa(info);
	one_move(info);
}

static void	three_move(t_info *info)
{
	int	tail;
	int	b_last2;
	int	b_last3;

	tail = info->total_len + 2;
	b_last2 = dlst_rbegin(info->b)->prev->value;
	b_last3 = dlst_rbegin(info->b)->prev->prev->value;
	if (b_last3 == tail)
		rrb(info);
	else if (b_last2 == tail)
	{
		if (b_last3 == tail - 1)
			rb(info);
		else
			sb(info);
	}
	pa(info);
	two_move(info);
}

void	final_three(t_info *info)
{
	if (info->b_size == 0)
		zero_move(info);
	else if (info->b_size == 1)
		one_move(info);
	else if (info->b_size == 2)
		two_move(info);
	else if (info->b_size == 3)
		three_move(info);
}
