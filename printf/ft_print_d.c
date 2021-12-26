/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:21:59 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/03 00:44:09 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putint(int n, int padding, int has_zero)
{
	int			ret;
	long long	num;

	ret = 0;
	num = n;
	if (num < 0)
	{
		if (!has_zero)
			ret += ft_putchar('-');
		num *= -1;
	}
	while (padding-- > 0)
		ret += ft_putchar('0');
	if (num / 10)
		ret += putint((int)(num / 10), 0, 0);
	ret += ft_putchar('0' + (num % 10));
	return (ret);
}

static int	print_d_core(t_spec *spc, int d, int d_len, int padding)
{
	int	ret;

	ret = 0;
	if (spc->has_zero && d < 0)
		ret += ft_putchar('-');
	if (!(spc->left_align))
		ret += ft_print_spaces(spc, d_len);
	if (spc->has_plus && d >= 0)
		ret += ft_putchar('+');
	else if (spc->has_space && d >= 0)
		ret += ft_putchar(' ');
	if (!(spc->precision == 0 && d == 0))
		ret += putint(d, padding, spc->has_zero);
	ret += ft_print_spaces(spc, d_len);
	return (ret);
}

int	ft_print_d(t_spec *spc, va_list ap)
{
	int	ret;
	int	d;
	int	d_len;
	int	padding;

	ret = 0;
	d = va_arg(ap, int);
	d_len = ft_get_digits(d, 10);
	if (spc->precision == 0 && d == 0)
		d_len = 0;
	padding = spc->precision - (d_len - (d < 0));
	if (padding < 0)
		padding = 0;
	d_len += padding;
	if (d >= 0 && (spc->has_plus || spc->has_space))
		spc->min_width--;
	ret += print_d_core(spc, d, d_len, padding);
	return (ret);
}
