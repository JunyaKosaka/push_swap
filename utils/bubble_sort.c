/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:11:21 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 18:11:50 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*ft_bubble_sort(int n, int *a)
{
	int	i;
	int	j;
	int	*ret;

	i = -1;
	ret = (int *)malloc(sizeof(int) * n);
	if (!ret)
		return (NULL);
	while (++i < n)
		ret[i] = a[i];
	i = 0;
	j = n - 1;
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
