/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:35:55 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/03 23:29:27 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_lx(unsigned int num, int padding)
{
	int	ret;

	ret = 0;
	while (padding-- > 0)
		ret += ft_putchar('0');
	if (num / 16)
		ret += put_lx((num / 16), 0);
	ret += ft_putchar("0123456789ABCDEF"[num % 16]);
	return (ret);
}

static int	print_lx_core(t_spec *spc, unsigned int u, int u_len, int padding)
{
	int	ret;

	ret = 0;
	if (!(spc->left_align))
		ret += ft_print_spaces(spc, u_len);
	if (spc->has_sharp)
		ret += write(1, "0X", 2);
	if (!(spc->precision == 0 && u == 0))
		ret += put_lx(u, padding);
	ret += ft_print_spaces(spc, u_len);
	return (ret);
}

int	ft_print_lx(t_spec *spc, va_list ap)
{
	int				ret;
	int				u_len;
	int				padding;
	unsigned int	u;

	ret = 0;
	u = va_arg(ap, unsigned int);
	u_len = ft_get_digits(u, 16);
	if (spc->has_sharp && u)
		u_len += 2;
	if (!u)
		spc->has_sharp = 0;
	if (spc->precision == 0 && u == 0)
		u_len = 0;
	padding = 0;
	if (u_len < spc->precision)
		padding = spc->precision - u_len;
	u_len += padding;
	ret += print_lx_core(spc, u, u_len, padding);
	return (ret);
}
