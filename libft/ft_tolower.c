/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:35:15 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/18 17:47:04 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	int	i = -1;

// 	while (++i <= 126)
// 	{
// 		if (tolower(i) != ft_tolower(i))
// 			printf("NG\n");
// 	}
// 	printf("Done\n");
// 	return (0);
// }