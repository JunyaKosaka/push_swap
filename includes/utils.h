/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:47:50 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/31 14:41:21 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <assert.h> // assertを後で消す
# include <malloc/malloc.h>
# include "../libft/libft.h"

# define STDOUT 1
# define STDERR 2
# define ARGMAX 1000
# define TRUE 1
# define FALSE 0
# define WALLMAX 50
# define SENTINEL -1


typedef enum e_operator
{
	SA = 1,
	SB,
	SS,
	PA,
	PB,
	PASS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}				t_operator;

typedef struct s_dlst
{
	int				value;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}				t_dlst;

typedef struct s_info
{
	t_dlst	*a;
	t_dlst	*b;
	t_dlst	*ans;
	int		wall[WALLMAX]; // WALLLIMIT
	int		border_a[2];
	int		border_b[2];
	int		a_size;
	int		b_size;
	int		target;
	int		divide;
	int		total_len;
	// ansも持てそう
}				t_info;

/*   operations   */
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);
void	pa(t_info *info);
void	pb(t_info *info);
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);


#endif // UTILS_H
