/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:26:59 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/03 19:49:23 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

void	*free_one(char **s)
{
	if (s)
	{
		free(*s);
		*s = NULL;
	}
	return (NULL);
}

void	*free_all(char **s1, char **s2)
{
	free_one(s1);
	free_one(s2);
	return (NULL);
}
