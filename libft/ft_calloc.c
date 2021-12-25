/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:25:31 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/28 11:57:58 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_over(size_t x, size_t y)
{
	return (y && x > SIZE_MAX / y);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	buff;

	if (is_over(count, size))
	{
		errno = ENOMEM;
		return (NULL);
	}
	buff = count * size;
	if (!buff)
		buff = 1;
	ret = (void *)malloc(buff);
	if (!ret)
		return (NULL);
	ft_bzero(ret, buff);
	return (ret);
}

// #include <stdio.h>
// #include <malloc/malloc.h>

// int	main(void)
// {
// 	size_t	nums[] = {0, 42, 1000, INT_MIN, LONG_MAX};
// 	size_t	cnt = 0;
// 	char	*pt;
// 	char	*ft_pt;
// 	int		i = -1;

// 	while (++i < 5)
// 	{
// 		pt = (char *)calloc(cnt, nums[i]);
// 		ft_pt = (char *)ft_calloc(cnt, nums[i]);
// 		// printf("%zu\n", malloc_size(pt));
// 		// printf("%zu\n", malloc_size(ft_pt));
// 		if (malloc_size(pt) != malloc_size(ft_pt))
// 			printf("%d: NG\n", i);
// 		free(pt);
// 		free(ft_pt);
// 	}
// 	printf("Done\n");
// 	return (0);
// }
