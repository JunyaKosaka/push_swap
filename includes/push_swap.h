/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:47:50 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/02 16:57:28 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./utils.h"

/*   ps_src   */
int		ps_sort(t_info *info);
int		small_size_sort(t_info *info);
int		block5_sort(t_info *info);
int		deque_sort(t_info *info);
void	divide_blocks_dq(t_info *info);
void	set_wall(t_info *info, int a_top_index);
int		set_border(int sum, int len);
void	set_border_a(t_info *info, int bottom_i, int top_i);
void	set_border_b(t_info *info, int bottom_i, int top_i);
void	divide_a_to_b(int len, t_info *info);
void	divide_b_to_a(int len, t_info *info);
void	push_a_to_b(int len, t_info *info);
void	push_b_to_a(t_info *info);
void	check_b(t_info *info);

#endif // PUSH_SWAP_H
