/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:35:55 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/02 20:28:29 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putuint(unsigned int num, int padding)
{
	int	ret;

	ret = 0;
	while (padding-- > 0)
		ret += ft_putchar('0');
	if (num / 10)
		ret += putuint((num / 10), 0);
	ret += ft_putchar('0' + (num % 10));
	return (ret);
}

static int	print_u_core(t_spec *spc, unsigned int u, int u_len, int padding)
{
	int	ret;

	ret = 0;
	if (!(spc->left_align))
		ret += ft_print_spaces(spc, u_len);
	if (!(spc->precision == 0 && u == 0))
		ret += putuint(u, padding);
	ret += ft_print_spaces(spc, u_len);
	return (ret);
}

int	ft_print_u(t_spec *spc, va_list ap)
{
	int				ret;
	int				u_len;
	int				padding;
	unsigned int	u;

	ret = 0;
	u = va_arg(ap, unsigned int);
	u_len = ft_get_digits(u, 10);
	if (spc->precision == 0 && u == 0)
		u_len = 0;
	padding = 0;
	if (u_len < spc->precision)
		padding = spc->precision - u_len;
	u_len += padding;
	ret += print_u_core(spc, u, u_len, padding);
	return (ret);
}
