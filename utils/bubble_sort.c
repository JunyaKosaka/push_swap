/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:11:21 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/02 14:23:56 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	*ft_bubble_sort(int total_len, int *a)
{
	int	i;
	int	j;
	int	*ret;

	i = -1;
	ret = (int *)malloc(sizeof(int) * total_len);
	if (!ret)
		return (NULL);
	while (++i < total_len)
		ret[i] = a[i];
	i = 0;
	j = total_len - 1;
	while (i < j)
	{
		while (i < j)
		{
			if (ret[i] > ret[i + 1])
				ft_swap(&ret[i], &ret[i + 1]);
			i++;
		}
		i = 0;
		j--;
	}
	return (ret);
}
