/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:44:21 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/18 02:09:10 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (' ' <= c && c <= '~');
}

// #include <stdio.h>
// #include <ctype.h>
// // ' ' : 32
// // '~' : 126
// int	main(void)
// {
// 	int		i = -1;
// 	while (++i <= 127)
// 	{
// 		if (ft_isprint(i) != isprint(i))
// 		{
// 			printf("NG\n");
// 			return (0);
// 		}
// 	}
// 	printf("Done\n");
// 	return (0);
// }
