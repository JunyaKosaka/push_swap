/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:42:43 by jkosaka           #+#    #+#             */
/*   Updated: 2021/11/27 20:23:47 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_spec
{
	int	c;
	int	min_width;
	int	precision;
	int	left_align;
	int	has_zero;
	int	has_plus;
	int	has_space;
	int	has_sharp;
}	t_spec;

typedef unsigned long long	t_ull;

int		ft_printf(const char *format, ...);
char	*ft_parse_spec(t_spec *spc, char *ptr, va_list ap);
int		ft_print_s(t_spec *spc, va_list ap);
int		ft_print_c(t_spec *spc, va_list ap);
int		ft_print_d(t_spec *spc, va_list ap);
int		ft_print_u(t_spec *spc, va_list ap);
int		ft_print_p(t_spec *spc, va_list ap);
int		ft_print_x(t_spec *spc, va_list ap);
int		ft_print_lx(t_spec *spc, va_list ap);
int		ft_print_percent(t_spec *spc);
int		ft_putchar(char c);
// int		ft_putstr(char *s);
int		ft_print_spaces(t_spec *spc, int num_width);
int		ft_get_digits(long long x, int base);
int		ft_get_digits_u(unsigned long long num, int base);

#endif // FT_PRINTF_H
