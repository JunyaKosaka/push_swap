/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:59:38 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 18:00:55 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error_handler(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void	ft_swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int	find_index(int n, int *arr, int value)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	isin(int border[2], int x)
{
	return (border[0] <= x && x < border[1]);
}
