/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:42:38 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/03 00:33:11 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_spec(t_spec *spc, va_list ap)
{
	if (spc->c == 'c')
		return (ft_print_c(spc, ap));
	if (spc->c == 's')
		return (ft_print_s(spc, ap));
	if (spc->c == 'p')
		return (ft_print_p(spc, ap));
	if (spc->c == 'd')
		return (ft_print_d(spc, ap));
	if (spc->c == 'i')
		return (ft_print_d(spc, ap));
	if (spc->c == 'u')
		return (ft_print_u(spc, ap));
	if (spc->c == 'x')
		return (ft_print_x(spc, ap));
	if (spc->c == 'X')
		return (ft_print_lx(spc, ap));
	if (spc->c == '%')
		return (ft_print_percent(spc));
	return (0);
}

static int	ft_printf_core(char *ptr, va_list ap)
{
	int		ret;
	int		temp;
	t_spec	spc;

	ret = 0;
	while (*ptr && ret < INT_MAX)
	{
		if (*ptr != '%')
		{
			ret += ft_putchar(*ptr);
			ptr++;
			continue ;
		}
		ptr = ft_parse_spec(&spc, ptr, ap);
		if (!ptr)
			return (-1);
		temp = print_spec(&spc, ap);
		if (INT_MAX - ret <= temp)
			return (-1);
		ret += temp;
	}
	if (ret == INT_MAX)
		return (-1);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	char	*ptr;
	int		ret;
	va_list	ap;

	ptr = (char *)format;
	va_start(ap, format);
	ret = ft_printf_core(ptr, ap);
	va_end(ap);
	return (ret);
}
