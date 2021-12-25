/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:25:23 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/17 18:19:12 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst == src || n == 0 )
		return (dst);
	while (src < dst && dst <= src + n)
	{
		ft_memcpy(dst + n - 1, src + n - 1, 1);
		n--;
	}
	ft_memcpy(dst, src, n);
	return (dst);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*src;
// 	char	*dst;
// 	src = ft_strdup("0123456");
// 	dst = src + 2;
// 	printf("  %s\n", dst);
// 	printf("%s\n", src);
// 	printf("----------\n");
// 	ft_memmove(dst, src, 3);
// 	printf("  %s\n", dst);
// 	printf("%s\n", src);
// 	return (0);
// }
