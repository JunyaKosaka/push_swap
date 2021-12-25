/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 00:28:36 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/18 02:08:06 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t n)
{
	ft_memset(b, '\0', n);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	buff[10];
// 	char	ft_buff[10];
// 	int		i = -1;

// 	while (++i < 10)
// 	{
// 		bzero(buff, i);
// 		ft_bzero(ft_buff, i);
// 		if (memcmp(buff, ft_buff, 10))
// 		{
// 			printf("NG\n");
// 			return (0);
// 		}
// 	}
// 	printf("Done\n");
// 	return (0);
// }
