/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 13:24:02 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/09 01:54:41 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

long	abs_v(long x)
{
	if (x < 0)
		x *= -1;
	return (x);
}

int	is_error(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (j == 0 && ft_strchr("-+", argv[i][j]))
				continue ;
			if (!ft_isdigit(argv[i][j]))
				return (true);
		}
		if (ft_atoi(argv[i]) == LONG_MAX)
			return (true);
		j = 0;
		while (++j < i)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (true);
		}
	}
	return (false);
}

int	*convert_to_int(int total_len, char *argv[])
{
	int	i;
	int	*ret;

	i = -1;
	ret = (int *)malloc(sizeof(int) * total_len);
	if (!ret)
		return (NULL);
	while (++i < total_len)
		ret[i] = ft_atoi(argv[i + 1]);
	return (ret);
}

int	is_sorted_info(t_info *info)
{
	int		min;
	t_dlst	*cur;

	if (info->b_size)
		return (false);
	cur = info->a->next;
	min = INT_MAX;
	while (cur->value != SENTINEL)
	{
		if (cur->value > min)
			return (false);
		min = cur->value;
		cur = cur->next;
	}
	return (true);
}

int	b_target_index(t_info *info, int target)
{
	int		i;
	t_dlst	*cur;

	i = 0;
	cur = info->b->next;
	while (cur->value != target)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}
