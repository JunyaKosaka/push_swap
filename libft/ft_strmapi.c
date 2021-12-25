/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:54:34 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/19 23:59:15 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	while (s[i])
	{
		ret[i] = (*f)(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

// static char	func(unsigned int i, char c)
// {
// 	return (c + i);
// }

// #include <stdio.h>

// int	main(void)
// {
// 	char	s[10][30] = {"aBcDe", "012"};
// 	char	*t;
// 	int		i = -1;

// 	while (++i < 2)
// 	{
// 		t = ft_strmapi(s[i], func);
// 		printf("%s\n", t);
// 	}
// 	printf("Done\n");
// 	return (0);
// }
