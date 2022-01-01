/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:47:50 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/01 21:02:11 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./utils.h"

/*   utils   */
long	cal_last_sum(int len, t_dlst *a);
void	ft_swap(int *x, int *y);
int		find_index(int n, int *arr, int value);
int		is_in_border(int border[2], int x);
int		is_sorted(int total_len, int *arr);
long	abs_v(long x);

int		error_handler(void);
int		push_swap(int argc, char *argv[]);
int		*ft_bubble_sort(int n, int *a);

void	show_one(t_dlst	*lst);
void	show_ans(t_dlst	*lst);
void	show(t_info info);
t_dlst	*compress_ans(t_dlst *ans);


/*   ps_src   */
int		ps_sort(t_info *info);
int		block5_sort(t_info *info);
int		deque_sort(t_info *info);
void	set_wall(t_info *info);
void	set_border_a(t_info *info, int bottom_i, int top_i);
void	set_border_b(t_info *info, int bottom_i, int top_i);
void	divide_a_to_b(int len, t_info *info);
void	divide_b_to_a(int len, t_info *info);
void	push_a_to_b(int len, t_info *info);
void	push_b_to_a(t_info *info);
void	divide_blocks(t_info *info);
void	init_stack(int total_len, t_info *info);

/*   dlst   */
t_dlst	*dlst_rbegin(t_dlst *lst);
t_dlst	*dlst_new(int value);
int		dlst_size(t_dlst *lst);
int		dlst_back(t_dlst *a);
void	dlst_addback(t_dlst **lst, t_dlst *new);
t_dlst	*dlst_popback(t_dlst **lst);
void	dlst_delone(t_dlst *lst);
void	dlst_clear(t_dlst **lst);
void	dlst_swap(t_dlst *a, t_dlst *b);

/*   free   */
int		free_all_info(t_info *info, int error);
void	*free_int_arr(int **arr);

#endif // PUSH_SWAP_H
