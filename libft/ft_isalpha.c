/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 08:41:22 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/19 18:40:48 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	c |= 'a' - 'A';
	return ('a' <= c && c <= 'z');
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	int		i = -1;
// 	while (++i <= 127)
// 	{
// 		if (ft_isalpha(i) != isalpha(i))
// 		{
// 			printf("NG\n");
// 			return (0);
// 		}
// 	}
// 	printf("Done\n");
// 	return (0);
// }
