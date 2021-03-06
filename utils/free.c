/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:35:41 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/09 10:36:47 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	*free_int_arr(int **arr)
{
	if (arr && *arr)
	{
		free(*arr);
		*arr = NULL;
	}
	return (NULL);
}

static void	free_info(t_info *info)
{
	if (!info)
		return ;
	dlst_clear(&(info->a));
	dlst_clear(&(info->b));
	dlst_clear(&(info->ans));
	free_int_arr(&(info->arr));
}

int	free_all_info(t_info *info, bool error)
{
	if (info)
		free_info(info);
	if (error)
		exit(error_handler());
	return (0);
}
