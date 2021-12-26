/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:17:29 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/29 13:46:07 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_get_digits(long long num, int base)
{
	int		ret;

	ret = 1;
	if (num < 0)
	{
		num *= -1;
		ret++;
	}
	if (num / base)
		ret += ft_get_digits(num / base, base);
	return (ret);
}

int	ft_get_digits_u(unsigned long long num, int base)
{
	int		ret;

	ret = 1;
	if (num / base)
		ret += ft_get_digits(num / base, base);
	return (ret);
}
