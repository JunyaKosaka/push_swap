/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:09:25 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/02 20:28:29 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(t_spec *spc, va_list ap)
{
	int		ret;
	char	c;

	ret = 0;
	c = va_arg(ap, int);
	if (!(spc->left_align))
		ret += ft_print_spaces(spc, 1);
	ret += ft_putchar(c);
	ret += ft_print_spaces(spc, 1);
	return (ret);
}
