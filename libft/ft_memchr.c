/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:31:53 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/21 14:11:40 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pt;

	pt = (unsigned char *)s;
	while (n--)
	{
		if (*pt == (unsigned char)c)
			return (pt);
		pt++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	s[] = "0123\0 abcd";
// 	char	set[] = "03a\0 d";
// 	void	*pt;
// 	void	*ft_pt;
// 	int		i = -1;
// 	size_t	len = 6;
// 	while (++i < 6)
// 	{
// 		pt = memchr(s, s[i], len);
// 		ft_pt = ft_memchr(s, s[i], len);
// 		if (pt != ft_pt)
// 			printf("NG\n");
// 	}
// 	printf("Done\n");
// 	return (0);
// }