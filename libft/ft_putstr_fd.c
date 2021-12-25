/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:11:40 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/18 17:11:52 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_fd(char **s, int fd, size_t len)
{
	write(fd, *s, len);
	*s += len;
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write_fd(&s, fd, len % INT_MAX);
	len /= INT_MAX;
	while (len--)
		write_fd(&s, fd, INT_MAX);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	s[10][30] = {"012345", "a b c", ""};
// 	int		i = -1;

// 	while (++i < 3)
// 	{
// 		ft_putstr_fd(s[i], 1);
// 		printf("\n");
// 	}
// 	printf("Done\n");
// }
