/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:11:34 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/21 14:11:49 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pt_1;
	unsigned char	*pt_2;

	pt_1 = (unsigned char *)s1;
	pt_2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n-- > 1 && *pt_1 == *pt_2)
	{
		pt_1++;
		pt_2++;
	}
	return (*pt_1 - *pt_2);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	s1[] = "0123456789";
// 	char	s2[] = "012abc";
// 	size_t	i = 0;

// 	while (i < 10)
// 	{
// 		int num1 = memcmp(s1, s2, i);
// 		int num2 = ft_memcmp(s1, s2, i);
// 		if (num1 != num2)
// 			printf("NG\n");
// 		i++;
// 	}
// 	printf("Done\n");
// 	return (0);
// }
