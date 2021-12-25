/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:32:02 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/18 00:40:34 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c -= 'a' - 'A';
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	int	i = -1;

// 	while (++i <= 126)
// 	{
// 		if (toupper(i) != ft_toupper(i))
// 			printf("NG\n");
// 	}
// 	printf("Done\n");
// 	return (0);
// }
