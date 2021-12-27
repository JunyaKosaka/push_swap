/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:35:41 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 19:49:32 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_info(t_info *info)
{
	if (!info)
		return ;
	ft_dlst_clear(&(info->a));
	ft_dlst_clear(&(info->b));
	free(info);
	info = NULL;
}

int	free_all_info(t_info *info, t_dlst *ans, int **arr)
{
	if (info)
		free_info(info);
	if (ans)
		ft_dlst_clear(&ans);
	if (arr)
		free_int_arr(arr);
	return (-1);
}

void	*free_int_arr(int **arr)
{
	if (arr)
	{
		free(*arr);
		*arr = NULL;
	}
	return (NULL);
}
