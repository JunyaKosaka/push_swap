/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:02:23 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/13 11:01:41 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dst && !dstsize)
		return (src_len);
	dst_len = ft_strlen(dst);
	ret = dst_len + src_len;
	if (dstsize < dst_len + 1)
		return (dstsize + src_len);
	ft_strlcpy(dst + dst_len, src, dstsize - dst_len);
	return (ret);
}

// dst NULL dstsize = 0の時はsegfault起こさない
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*dst;
// 	char	*ft_dst;
// 	char	*src;
// 	size_t	i = 0;
// 	size_t	num1 = 0;
// 	size_t	num2 = 0;
// 	char	s[] = "dest";

// 	// dst = (char *)malloc(sizeof(char) * 50);
// 	// ft_dst = (char *)malloc(sizeof(char) * 50);
// 	src = (char *)malloc(sizeof(char) * 50);
// 	src = ft_strdup("source");
// 	while (i < 20)
// 	{
// 		dst = ft_strdup(s);
// 		ft_dst = ft_strdup(s);
// 		// dst = NULL;
// 		// ft_dst = NULL;
// 		num1 = strlcat(dst, src, i);
// 		num2 = ft_strlcat(ft_dst, src, i);
// 		printf("%zu %s\n", num2, ft_dst);
// 		// printf("%zu %s\n", num1, dst);
// 		if (num1 != num2)
// 			printf("NG\n");
// 		if (ft_strncmp(dst, ft_dst, 10))
// 			printf("str NG\n");
// 		// printf("dst    : %s\n", dst);
// 		// printf("ft_dst : %s\n", ft_dst);
// 		i++;
// 	}
// 	free(dst);
// 	free(ft_dst);
// 	free(src);
// 	printf("Done\n");
// 	return (0);
// }
