/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:40:10 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/19 15:11:24 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s1);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, len + 1);
	return (ret);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*pt;
// 	char	*ft_pt;
// 	char	s[10][30] = {"abc", "", "\0", "   123"};
// 	int		i = -1;

// 	while (++i < 4)
// 	{
// 		pt = strdup(s[i]);
// 		ft_pt = ft_strdup(s[i]);
// 		if (*pt != *ft_pt)
// 			printf("NG\n");
// 		free(pt);
// 		free(ft_pt);
// 	}
// 	printf("Done\n");
// 	return (0);
// }