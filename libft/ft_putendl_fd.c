/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:07:23 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/18 16:35:04 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	s[10][30] = {"012345", "a b c", ""};
// 	int		i = -1;

// 	while (++i < 3)
// 		ft_putendl_fd(s[i], 1);
// 	printf("Done\n");
// }