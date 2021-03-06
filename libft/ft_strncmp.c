/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:04:18 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/03 19:51:35 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*pt_1;
	unsigned char	*pt_2;

	pt_1 = (unsigned char *)s1;
	pt_2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((n-- > 1) && (*pt_1 == *pt_2) && (*pt_1 != '\0'))
	{
		pt_1++;
		pt_2++;
	}
	return (*pt_1 - *pt_2);
}
