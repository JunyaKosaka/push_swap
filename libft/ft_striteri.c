/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:50:34 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/06 02:11:34 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (*s)
	{
		(*f)(i, s);
		i++;	
		s++;
	}
}

// #include <stdio.h>

// static void	func(unsigned int i, char *c)
// {
// 	*c += i;
// }

// int	main(void)
// {
// 	char	s[10][30] = {"aBcDe", "012"};
// 	int		i = -1;

// 	while (++i < 2)
// 	{
// 		ft_striteri(s[i], func);
// 		printf("%s\n", s[i]);
// 	}
// 	printf("Done\n");
// 	return (0);
// }
