/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:43:00 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/27 17:16:01 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_over(long n, int m, int sign)
{
	if (sign)
		return (n > (INT_MAX - m) / 10);
	else
		return (n > ((long)INT_MAX + 1 - m) / 10);
}

static int	is_space(int c)
{
	return (('\t' <= c && c <= '\r') || c == ' ');
}

long	ft_atoi(const char *str)
{
	long	ret;
	int		sign;

	sign = 1;
	ret = 0;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = 44 - *str;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (is_over(ret, *str - '0', sign))
			return (LONG_MAX);
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (ret * sign);
}

// #include <stdio.h>
// #include <libc.h>

// int	main(void)
// {
// 	int	x = ft_atoi("03");
// 	printf("%d\n", x);
// 	// int		i = -1;
// 	// char	s[10][30] = {"123abc", " +92233720368547", "-2147483648\n"};
// 	// while (++i < 3)
// 	// {
// 	// 	if (atoi(s[i]) != ft_atoi(s[i]))
// 	// 		printf("NG\n");
// 	// 	printf("%d\n", ft_atoi(s[i]));
// 	// }
// 	// printf("Done\n");
// 	return (0);
// }
