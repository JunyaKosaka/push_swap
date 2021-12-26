/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_spec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:28:22 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/17 18:06:22 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*parse_flag(t_spec *spc, char **ptr)
{
	while (**ptr && ft_strchr("0-#+ ", **ptr))
	{
		if (**ptr == '0')
			spc->has_zero = 1;
		else if (**ptr == '-')
			spc->left_align = 1;
		else if (**ptr == '#')
			spc->has_sharp = 1;
		else if (**ptr == '+')
			spc->has_plus = 1;
		else if (**ptr == ' ')
			spc->has_space = 1;
		(*ptr)++;
	}
	return (*ptr);
}

static char	*parse_min_width(t_spec *spc, char **ptr, va_list ap)
{
	if (ft_isdigit(**ptr))
	{
		spc->min_width = ft_atoi(*ptr);
		if (spc->min_width == -1)
			return (NULL);
		*ptr += ft_get_digits(spc->min_width, 10);
	}
	else if (**ptr == '*')
	{
		spc->min_width = va_arg(ap, int);
		(*ptr)++;
	}
	return (*ptr);
}

static char	*parse_dot(t_spec *spc, char **ptr, va_list ap)
{
	if (**ptr != '.')
		return (*ptr);
	while (**ptr == '.')
		(*ptr)++;
	spc->precision = 0;
	if (ft_isdigit(**ptr))
	{
		spc->precision = ft_atoi(*ptr);
		if (spc->precision == -1)
			return (NULL);
		while (ft_isdigit(**ptr))
		{
			printf("65:%c\n", **ptr);
			(*ptr)++;
		}
		// printf("65:%c\n", **ptr); printf("%.03d", 3)
		*ptr += ft_get_digits(spc->precision, 10);
	}
	else if (**ptr == '*')
	{
		spc->precision = va_arg(ap, int);
		(*ptr)++;
	}
	while (ft_isdigit(**ptr))
		(*ptr)++;
	// printf("73:%c\n", **ptr);
	return (*ptr);
}

static void	init_spc(t_spec *spc)
{
	spc->c = 0;
	spc->min_width = -1;
	spc->precision = -1;
	spc->left_align = 0;
	spc->has_zero = 0;
	spc->has_sharp = 0;
	spc->has_space = 0;
	spc->has_plus = 0;
}

char	*ft_parse_spec(t_spec *spc, char *ptr, va_list ap)
{
	ptr++;
	init_spc(spc);
	ptr = parse_flag(spc, &ptr);
	ptr = parse_min_width(spc, &ptr, ap);
	if (!ptr)
		return (NULL);
	ptr = parse_dot(spc, &ptr, ap);
	if (!ptr)
		return (NULL);
	if (spc->left_align || spc->precision >= 0)
		spc->has_zero = 0;
	if (spc->has_plus)
		spc->has_space = 0;
	if (*ptr && ft_strchr("cspdiuxX%", *ptr))
	{
		spc->c = *ptr;
		return (++ptr);
	}
	return (ptr);
}
