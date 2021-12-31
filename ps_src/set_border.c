/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_border.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:59:53 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/31 14:05:32 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_border_a(t_info *info, int bottom_i, int top_i)
{
	info->border_a[0] = info->wall[bottom_i];
	info->border_a[1] = info->wall[top_i];
}

void	set_border_b(t_info *info, int bottom_i, int top_i)
{
	info->border_b[0] = info->wall[bottom_i];
	info->border_b[1] = info->wall[top_i];
}