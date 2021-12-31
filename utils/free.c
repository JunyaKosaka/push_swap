/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:35:41 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/31 11:59:21 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_info(t_info *info)
{
	if (!info)
		return ;
	dlst_clear(&(info->a));
	dlst_clear(&(info->b));
	dlst_clear(&(info->ans));
}

int	free_all_info(t_info *info, int **arr, int error)
{
	if (info)
		free_info(info);
	if (arr && *arr)
		free_int_arr(arr);
	if (error)
		exit(error_handler());
	return (0);
}

void	*free_int_arr(int **arr)
{
	if (arr && *arr)
	{
		free(*arr);
		*arr = NULL;
	}
	return (NULL);
}
