/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_border.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:57:33 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 17:58:34 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	set_border_a(t_info *info, int a, int b)
{
	info->border_a[0] = a;
	info->border_a[1] = b;
}

void	set_border_b(t_info *info, int a, int b)
{
	info->border_b[0] = a;
	info->border_b[1] = b;
}
