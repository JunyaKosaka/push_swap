/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:37:14 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/21 14:12:22 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (!(*needle))
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack && needle_len <= len)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	s1[] = "012345";
// 	char	s2[] = "23";
// 	size_t	i = 0;
// 	char	*pt;
// 	char	*ft_pt;

// 	while (i < 20)
// 	{
// 		pt = strnstr(s1, s2, i);
// 		ft_pt = ft_strnstr(s1, s2, i);
// 		printf("%s\n", pt);
// 		if (pt != ft_pt)
// 			printf("NG\n");
// 		i++;
// 	}
// 	printf("Done\n");
// 	return (0);
// }
