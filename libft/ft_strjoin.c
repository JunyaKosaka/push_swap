/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:19:14 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/21 14:12:05 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, ft_strlen(s1) + 1);
	ft_strlcat(ret, s2, size + 1);
	return (ret);
}

// #include <stdio.h>

// int	main(void)
// { 
// 	char	s[10][10] = {"abc", "012", "", "\0", " abc", end"};
// 	int		i = -1;
// 	char	*t;

// 	while (++i < 5)
// 	{
// 		t = ft_strjoin(s[i], s[i + 1]);
// 		printf("%s\n", t);
// 	}
// 	return (0);
// }
