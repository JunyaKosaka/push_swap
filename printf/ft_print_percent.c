/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 00:31:34 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/02 20:44:53 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(t_spec *spc)
{
	int	ret;
	int	percent_len;

	ret = 0;
	percent_len = 1;
	if (!(spc->left_align))
		ret += ft_print_spaces(spc, 1);
	ret += ft_putchar('%');
	ret += ft_print_spaces(spc, 1);
	return (ret);
}
