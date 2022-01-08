/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:35:28 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/09 01:18:45 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	command_handler(t_info *info, char *command)
{
	if (!(ft_strncmp("sa\n", command, 3)))
		sa(info);
	else if (!(ft_strncmp("sb\n", command, 3)))
		sb(info);
	else if (!(ft_strncmp("ss\n", command, 3)))
		ss(info);
	else if (!(ft_strncmp("pa\n", command, 3)))
		pa(info);
	else if (!(ft_strncmp("pb\n", command, 3)))
		pb(info);
	else if (!(ft_strncmp("ra\n", command, 3)))
		ra(info);
	else if (!(ft_strncmp("rb\n", command, 3)))
		rb(info);
	else if (!(ft_strncmp("rr\n", command, 3)))
		rr(info);
	else if (!(ft_strncmp("rra\n", command, 4)))
		rra(info);
	else if (!(ft_strncmp("rrb\n", command, 4)))
		rrb(info);
	else if (!(ft_strncmp("rrr\n", command, 4)))
		rrr(info);
	else
		exit(free_all_info(info, TRUE));
}

static void	judge_ans(t_info *info)
{
	if (is_sorted_info(info))
		ft_putendl_fd("OK", STDOUT);
	else
		ft_putendl_fd("KO", STDOUT);
}

int	checker(int argc, char *argv[])
{
	t_info	info;
	char	*command;

	if (argc == 1)
		return (0);
	if (is_error(argc, argv))
		exit(error_handler());
	info.total_len = argc - 1;
	info.arr = convert_to_int(info.total_len, argv);
	if (!(info.arr))
		exit(free_all_info(&info, TRUE));
	init_stack(&info);
	command = get_next_line(&info);
	while (command)
	{
		command_handler(&info, command);
		free(command);
		command = get_next_line(&info);
	}
	free(command);
	judge_ans(&info);
	return (free_all_info(&info, FALSE));
}
