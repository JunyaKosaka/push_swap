/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:47:27 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/19 11:54:56 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	left;
	unsigned int	right;

	if (!s1)
		return (NULL);
	if (!set || !(*s1))
		return (ft_strdup(s1));
	left = 0;
	right = ft_strlen(s1) - 1;
	while (s1[left] && ft_strchr(set, s1[left]))
		left++;
	while (left <= right && ft_strchr(set, s1[right]))
		right--;
	return (ft_substr(s1, left, 1 + right - left));
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	s[10][30] = {"123212321", " a b c d ", "", " "};
// 	char	set[10][30] = {"12", "a ", "yz", "\0"};
// 	char	*t;
// 	int		i = -1;

// 	while (++i < 4)
// 	{
// 		t = ft_strtrim(s[i], set[i]);
// 		printf("t:%s\n", t);
// 	}
// 	printf("Done\n");
// 	return (0);
// }
