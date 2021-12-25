/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:01:56 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/21 14:11:56 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pt_dst;
	unsigned char	*pt_src;

	if (dst == src)
		return (dst);
	pt_dst = (unsigned char *)dst;
	pt_src = (unsigned char *)src;
	while (n--)
		*pt_dst++ = *pt_src++;
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// static int	is_good(const void *src, size_t len)
// {
// 	char		s[] = "01234";
// 	char		*buff;
// 	char		*ft_buff;

// 	buff = ft_strdup(s);
// 	ft_buff = ft_strdup(s);
// 	memcpy(buff, src, len);
// 	ft_memcpy(ft_buff, src, len);
// 	if (memcmp(buff, ft_buff, len))
// 		return (0);
// 	return (1);
// }

// int	main(void)
// {
// 	char	srcs[10][10] = {"", "  space ", "\0"};
// 	int		i = -1;
// 	while (++i < 3)
// 	{
// 		if (!is_good(srcs[i], 10))
// 			printf("NG\n");
// 	}
// 	printf("Done\n");
// 	return (0);
// }
