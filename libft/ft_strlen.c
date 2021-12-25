/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:45:24 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/18 02:09:10 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	ind;

	ind = 0;
	while (s[ind])
		ind++;
	return (ind);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	s[10][10] = {"a", "  test  \0", " ", "\0"};
// 	int		i = -1;
// 	while (++i < 4)
// 	{
// 		if (ft_strlen(s[i]) != strlen(s[i]))
// 		{
// 			printf("NG\n");
// 			return (0);
// 		}
// 	}
// 	printf("Done\n");
// 	return (0);
// }
