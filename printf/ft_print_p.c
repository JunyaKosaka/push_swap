/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:35:43 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/03 23:57:23 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_x(uintptr_t num, int padding)
{
	int	ret;

	ret = 0;
	while (padding-- > 0)
		ret += ft_putchar('0');
	if (num / 16)
		ret += put_x((num / 16), 0);
	ret += ft_putchar("0123456789abcdef"[num % 16]);
	return (ret);
}

static int	print_p_core(t_spec *spc, uintptr_t p, int p_len, int padding)
{
	int	ret;

	ret = 0;
	if (!(spc->left_align))
		ret += ft_print_spaces(spc, p_len);
	ret += write(1, "0x", 2);
	ret += put_x(p, padding);
	ret += ft_print_spaces(spc, p_len);
	return (ret);
}

int	ft_print_p(t_spec *spc, va_list ap)
{
	int			ret;
	uintptr_t	p;
	int			p_len;
	int			padding;

	ret = 0;
	p = (uintptr_t)va_arg(ap, void *);
	p_len = ft_get_digits_u(p, 16) + 2;
	padding = spc->precision - (p_len - (p < 0));
	if (padding < 0)
		padding = 0;
	p_len += padding;
	ret += print_p_core(spc, p, p_len, padding);
	return (ret);
}
