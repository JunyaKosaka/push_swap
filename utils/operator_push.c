/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:15:36 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/04 21:16:36 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	pa(t_info *info)
{
	t_dlst	*new;
	t_dlst	*last;

	if (dlst_size((info->b)) == 0)
		return ;
	new = dlst_new(PA);
	if (!new)
		exit(free_all_info(info, TRUE));
	dlst_pushback(&(info->ans), new);
	last = dlst_popback(&(info->b));
	dlst_pushback(&(info->a), last);
	info->a_size++;
	info->b_size--;
}

void	pb(t_info *info)
{
	t_dlst	*new;
	t_dlst	*last;

	if (dlst_size((info->a)) == 0)
		return ;
	new = dlst_new(PB);
	if (!new)
		exit(free_all_info(info, TRUE));
	dlst_pushback(&(info->ans), new);
	last = dlst_popback(&(info->a));
	dlst_pushback(&(info->b), last);
	info->b_size++;
	info->a_size--;
}
