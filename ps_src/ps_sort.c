/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:35:28 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/09 00:04:47 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_sort(t_info *info)
{
	if (info->total_len < 40)
		return (small_size_sort(info));
	else if (info->total_len < 200)
		return (chunk5_sort(info));
	else
		return (deque_sort(info));
}
