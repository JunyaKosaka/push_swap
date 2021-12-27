/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:47:50 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/28 01:42:36 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <assert.h> // assertを後で消す
# include <malloc/malloc.h>
# include "./libft/libft.h"
# include "./printf/ft_printf.h"

enum operator {
	SA = 1,
	SB,
	SS, // 3 ok
	PA,
	PB,
	PASS, // 6 例外処理
	RA,
	RB,
	RR, // 9 ok
	RRA,
	RRB,
	RRR, // 12 ok
};

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
	int		target;
	int		divide;
	int		border_a[2]; // [0]が下限[1]が上限
	int		border_b[2];
	int		total;
	int		a_size;
	int		b_size;
}				t_info;

int		push_swap(int argc, char *argv[]);
void	*free_int_arr(int **arr);
int		free_all_info(t_info *info, t_dlst *ans, int **arr);
void	free_info(t_info *info);
int		error_handler(void);
int		*ft_bubble_sort(int n, int *a);
void	ft_swap(int *x, int *y);
int		find_index(int n, int *arr, int value);
int		solve(int total_len, int *arr);
int		solve_five(int n, int *arr);
int		solve_13(int total_len, int *arr);
int		solve_9(int total_len, int *arr);
int		ft_is_sorted(int n, int *arr);
t_info	*init_stack(int total_len, int *arr, t_dlst **ans);
t_dlst	*ft_dlst_last(t_dlst *lst);
void	ft_dlst_addback(t_dlst **lst, t_dlst *new);
t_dlst	*ft_dlst_popback(t_dlst **lst);
void	ft_dlst_delone(t_dlst *lst);
void	ft_dlst_clear(t_dlst **lst);
t_dlst	*ft_dlst_new(long value);
int		ft_dlst_size(t_dlst *lst);
void	ft_dlst_swap(t_dlst *a, t_dlst *b);
int		dlst_back(t_dlst *a);
void	sa(t_info *info, t_dlst **ans);
void	sb(t_info *info, t_dlst **ans);
void	ss(t_info *info, t_dlst **ans);
void	pa(t_info *info, t_dlst **ans);
void	pb(t_info *info, t_dlst **ans);
void	ra(t_info *info, t_dlst **ans);
void	rb(t_info *info, t_dlst **ans);
void	rr(t_info *info, t_dlst **ans);
void	rra(t_info *info, t_dlst **ans);
void	rrb(t_info *info, t_dlst **ans);
void	rrr(t_info *info, t_dlst **ans);
int		push_a_to_b(int len, t_info *info, t_dlst **ans);
void	push_b_to_a(t_info *info, t_dlst **ans);
// void	quick_sort_b(int len, t_info *info, t_dlst **ans);
int		isin(int border[2], int x);
void	set_border_a(t_info *info, int a, int b);
void	divide_a_to_b(int len, t_info *info, t_dlst **ans);
void	divide_b_to_a(int len, t_info *info, t_dlst **ans);
void	set_border_b(t_info *info, int a, int b);
t_dlst	*compress_ans(t_dlst *ans);
long	cal_last_sum(int len, t_dlst *a);
void	show_one(t_dlst	*lst);
void	show_ans(t_dlst	*lst);
void	show(t_info *info);

#endif // PUSH_SWAP_H
