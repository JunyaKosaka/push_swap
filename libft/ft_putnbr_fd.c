/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:10:05 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/18 16:38:20 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr(unsigned int n, int fd)
{
	char	c;

	if (n / 10)
		putnbr(n / 10, fd);
	c = '0' + (n % 10);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	if (n >= 0)
		number = n;
	else
	{
		write(fd, "-", 1);
		number = (unsigned int)((n + 1) * -1) + 1;
	}
	putnbr(number, fd);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	nums[] = {INT_MIN, -42, 0, INT_MAX};
// 	int	i = -1;

// 	while (++i < 4)
// 	{
// 		ft_putnbr_fd(nums[i], 1);
// 		printf("\n");
// 	}
// 	printf("Done\n");
// }
