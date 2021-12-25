/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 08:49:05 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/19 15:29:29 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len)
		len = s_len;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	if (start < s_len)
		ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	s[] = "abcdef";
// 	char	*t;
// 	int		i = -1;
// 	int		len = 3;

// 	while (++i < 10)
// 	{
// 		t = ft_substr(s, i, len);
// 		printf("%s\n", t);	
// 	}
// 	return (0);
// }
