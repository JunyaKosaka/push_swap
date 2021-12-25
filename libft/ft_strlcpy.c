/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 23:46:39 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/18 02:09:10 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;

	ret = ft_strlen(src);
	if (!dstsize)
		return (ret);
	dstsize -= 1;
	while (*src && dstsize-- > 0)
		*dst++ = *src++;
	*dst = '\0';
	return (ret);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*dst;
// 	char	*ft_dst;
// 	char	*src;
// 	int		i = -3;
// 	src = ft_strdup("source");
// 	dst = ft_strdup("destination");
// 	ft_dst = ft_strdup("destination");
// 	while (++i < 10)
// 	{
// 		if (strlcpy(dst, src, i) != ft_strlcpy(ft_dst, src, i))
// 			printf("NG\n");
// 		if (ft_strncmp(dst, ft_dst, 10))
// 			printf("NG\n");
// 	}
// 	printf("Done\n");
// }
