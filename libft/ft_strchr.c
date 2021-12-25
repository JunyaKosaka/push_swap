/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:31:53 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/21 10:11:13 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	s[] = "123 string 321";
// 	char	set[] = "42 \0set";
// 	char	*pt;
// 	char	*ft_pt;
// 	int		i = -1;

// 	while (++i < 7)
// 	{
// 		pt = strchr(s, set[i]);
// 		ft_pt = ft_strchr(s, set[i]);
//		printf("%c %s\n", set[i], pt);
// 		if (pt != ft_pt)
// 			printf("NG\n");
// 	}
// 	printf("Done\n");
// 	return (0);
// }
