/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:49:30 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/21 10:10:32 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pt;

	pt = (unsigned char *)b;
	while (len--)
		*pt++ = (unsigned char)c;
	return (b);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	buff[30];
// 	char	ft_buff[30];
// 	int		i = -10;
// 	int		len = 3;

// 	while (++i < 200)
// 	{
// 		memset(buff, i, len);
// 		memset(ft_buff, i, len);
// 		if (memcmp(buff, ft_buff, len))
// 		{
// 			printf("NG\n");
// 			return (0);
// 		}
// 		len = (len + 13) % 17;
// 	}
// 	printf("Done\n");
// 	return (0);
// }
