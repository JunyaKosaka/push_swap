/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:47:50 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/09 01:37:33 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./utils.h"

/*   ps_src   */
int		push_swap(int argc, char *argv[]);
int		ps_sort(t_info *info);
int		small_size_sort(t_info *info);
int		chunk5_sort(t_info *info);
void	change_lead(t_info *info);
int		deque_sort(t_info *info);
void	divide_chunks_dq(t_info *info);
void	set_wall(t_info *info, int a_top_index);
int		set_border(int sum, int len);
void	set_border_a(t_info *info, int bottom_i, int top_i);
void	set_border_b(t_info *info, int bottom_i, int top_i);
void	divide_a_to_b(int len, t_info *info);
void	divide_b_to_a(int len, t_info *info);
void	push_a_to_b(int len, t_info *info);
void	push_b_to_a(t_info *info);
void	check_b(t_info *info);
int		check_two(t_dlst *last, int target);
int		check_three(t_dlst *last, int target);
void	final_three(t_info *info);

#endif // PUSH_SWAP_H
