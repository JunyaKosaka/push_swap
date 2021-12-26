/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:02:19 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/02 20:46:03 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putnstr(char *str, int len)
{
	if (len < INT_MAX)
		write(1, str, len);
	return (len);
}

int	ft_print_s(t_spec *spc, va_list ap)
{
	int		ret;
	size_t	s_len;
	char	*str;

	ret = 0;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	s_len = ft_strlen(str);
	if (s_len > INT_MAX)
		s_len = INT_MAX;
	if (0 <= spc->precision && spc->precision < (int)s_len)
		s_len = spc->precision;
	if (!(spc->left_align))
		ret += ft_print_spaces(spc, (int)s_len);
	ret += putnstr(str, s_len);
	ret += ft_print_spaces(spc, (int)s_len);
	return (ret);
}
