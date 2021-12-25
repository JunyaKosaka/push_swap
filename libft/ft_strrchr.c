/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:31:53 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/21 14:12:32 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pt;
	char	*next;

	pt = NULL;
	next = (char *)s;
	while (*next)
	{
		if (*next == (char)c)
			pt = next;
		next++;
	}
	if (*next == (char)c)
		pt = next;
	return (pt);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	s[] = "123 string 321";
// 	// char	s[] = "";
// 	char	set[] = "42 \0set";
// 	char	*pt;
// 	char	*ft_pt;
// 	int		i = -1;

// 	while (++i < 7)
// 	{
// 		pt = strrchr(s, set[i]);
// 		ft_pt = ft_strrchr(s, set[i]);
// 		printf("%c: %s\n", set[i], pt);
// 		if (pt != ft_pt)
// 			printf("NG\n");
// 	}
// 	printf("Done\n");
// 	return (0);
// }
