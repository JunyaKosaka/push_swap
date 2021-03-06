/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:47:50 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/09 10:37:28 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>

# include "../libft/libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define ARGMAX 1001
# define WALLMAX 50
# define SENTINEL -1
# define LEAD 3

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
	int		*arr;
	int		wall[WALLMAX];
	int		border_a[2];
	int		border_b[2];
	int		a_size;
	int		b_size;
	int		target;
	int		divide;
	int		lead;
	int		total_len;
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

/*   utils   */
long	cal_last_sum(int len, t_dlst *a);
void	ft_swap(int *x, int *y);
int		find_index(int n, int *arr, int value);
bool	is_in_border(int border[2], int x);
bool	is_sorted(int total_len, int *arr);
int		diff(int x, int y);
long	abs_v(long x);
void	init_stack(t_info *info);
int		*convert_to_int(int total_len, char *argv[]);
bool	is_error(int argc, char *argv[]);
int		error_handler(void);
int		*ft_bubble_sort(int n, int *a);
bool	is_sorted_info(t_info *info);
int		b_target_index(t_info *info, int target);
t_dlst	*compress_ans(t_info *info);
void	show_one(t_dlst	*lst);
void	show_ans(t_dlst	*lst);
void	show(t_info info);

/*   dlst   */
t_dlst	*dlst_rbegin(t_dlst *lst);
t_dlst	*dlst_new(int value);
int		dlst_size(t_dlst *lst);
int		dlst_back(t_dlst *a);
void	dlst_pushback(t_dlst **lst, t_dlst *new);
t_dlst	*dlst_popback(t_dlst **lst);
void	dlst_delone(t_dlst *lst);
void	dlst_clear(t_dlst **lst);
void	dlst_swap(t_dlst *a, t_dlst *b);

/*   free   */
int		free_all_info(t_info *info, bool error);
void	*free_int_arr(int **arr);

#endif // UTILS_H
