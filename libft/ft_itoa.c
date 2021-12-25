/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 16:19:11 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/12 17:05:0 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(int n)
{
	int	ret;

	ret = 0;
	if (n <= 0)
		ret = 1;
	while (n)
	{
		ret++;
		n /= 10;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char			*ret;
	int				size;
	unsigned int	number;

	size = count_size(n);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
	{
		number = (unsigned int)((n + 1) * -1) + 1;
		ret[0] = '-';
	}
	else
		number = n;
	ret[size] = '\0';
	while (number)
	{
		ret[--size] = '0' + (number % 10);
		number /= 10;
	}
	return (ret);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s;
// 	int		nums[4] = {-19872433, INT_MAX, INT_MIN, 0};
// 	int		i = -1;
// 	while (++i < 4)
// 	{
// 		s = ft_itoa(nums[i]);
// 		printf("%s\n", s);
// 	}
// 	printf("Done\n");
// 	return (0);
// }
