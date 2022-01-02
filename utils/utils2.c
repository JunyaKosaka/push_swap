/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 13:24:02 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/03 01:22:46 by jkosaka          ###   ########.fr       */
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
				return (1);
		}
		if (ft_atoi(argv[i]) == LONG_MAX)
			return (1);
		j = 0;
		while (++j < i)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
		}
	}
	return (0);
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
