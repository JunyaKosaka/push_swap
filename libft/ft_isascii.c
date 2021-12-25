/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:41:25 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/19 19:48:30 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

// #include <stdio.h>
// #include <ctype.h>

// int	main(void)
// {
// 	int		i = -10;
// 	while (++i <= 200)
// 	{
// 		if (ft_isascii(i) != isascii(i))
// 		{
// 			printf("NG\n");
// 			return (0);
// 		}
// 	}
// 	printf("Done\n");
// 	return (0);
// }
