/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:53:55 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/17 16:24:46 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	s;

	s = (unsigned char)c;
	write(fd, &s, 1);
}

// void	ft_putchar_fd(char c, int fd)
// {
// 	unsigned char	s;
// 	unsigned char	head;
// 	unsigned char	tail;

// 	s = (unsigned char)c;
// 	if (s < (1 << 7))
// 		write(fd, &s, 1);
// 	else
// 	{
// 		head = (s >> 6) | 0b11000000;
// 		tail = (s & 0b00111111) | 0b10000000;
// 		write(fd, &head, 1);
// 		write(fd, &tail, 1);
// 	}
// }

// #include <stdio.h>

// int	main(void)
// {
// 	unsigned char	c = 32;

// 	while ((int) c <= 200)
// 	{
// 		ft_putchar_fd(c, 1);
// 		if (((int) c == 160)) printf("--  160  --\n");
// 		c++;
// 	}
// 	printf(" <- end\nDone\n");
// 	return (0); 
// }
