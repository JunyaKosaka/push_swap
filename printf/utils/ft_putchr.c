/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:17:24 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/03 23:56:14 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar(char c)
{
	unsigned char	s;

	s = (unsigned char)c;
	return (write(1, &s, 1));
}

static int	ft_putspace(t_spec *spc)
{
	if (spc->has_zero)
		return (ft_putchar('0'));
	else
		return (ft_putchar(' '));
}

int	ft_print_spaces(t_spec *spc, int num_width)
{
	int	ret;

	ret = 0;
	while (spc->min_width > num_width)
	{
		ret += ft_putspace(spc);
		spc->min_width--;
	}
	return (ret);
}
