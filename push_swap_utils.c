/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 00:09:37 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/26 11:30:24 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_handler(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void	ft_swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int	*ft_bubble_sort(int n, int *a)
{
	int	i;
	int	j;
	int	*ret;

	i = -1;
	ret = (int *)malloc(sizeof(int) * n);
	while (++i < n)
		ret[i] = a[i];
	i = 0;
	j = n - 1;
	while (i < j)
	{
		while (i < j)
		{
			if (ret[i] > ret[i + 1])
				ft_swap(&ret[i], &ret[i + 1]);
			i++;
		}
		i = 0;
		j--;
	}
	return (ret);
}

int	*convert_to_int(int n, char *argv[])
{
	int	i;
	int	*ret;

	i = -1;
	ret = (int *)malloc(sizeof(int) * (n - 1));
	while (++i < n)
		ret[i] = ft_atoi(argv[i + 1]);
	return (ret);
}

int	find_index(int n, int *arr, int value)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	isin(int border[2], int x)
{
	return (border[0] <= x && x < border[1]);
}

void	set_border_a(t_info *info, int a, int b)
{
	info->border_a[0] = a;
	info->border_a[1] = b;
}

void	set_border_b(t_info *info, int a, int b)
{
	info->border_b[0] = a;
	info->border_b[1] = b;
}

void	show_one(t_dlst	*lst)
{
	t_dlst	*cur;

	cur = lst;
	cur = cur->prev;
	while (cur->value != -1)
	{
		printf("%d\n", cur->value);
		cur = cur->prev;
	}
}

void	show_ans(t_dlst	*lst)
{
	t_dlst	*cur;

	cur = lst;
	cur = cur->next;
	char	*s[] = {"", "sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	while (cur->value != -1)
	{
		ft_printf("%s\n", s[cur->value]);
		cur = cur->next;
	}
}

void	show(t_info *info)
{
	printf("== a ==\n");
	show_one(info->a);
	printf("== b ==\n");
	show_one(info->b);
	printf("====\n");
}

static int	diff(int x, int y)
{
	if (x > y)
		return (x - y);
	else
		return (y - x);
}

static int	convert(int x, int y)
{
	return ((x + y + 1) / 2 + 1);
}

static int compress_cand(int nv)
{
	return (nv == 3 || nv == 6 || nv == 8 || nv == 11);
}

t_dlst	*compress_ans(t_dlst *ans)
{
	int		new_value;
	t_dlst	*new_ans;
	t_dlst	*next;

	new_ans = NULL;
	ft_dlst_addback(&new_ans, ft_dlst_new(-1));
	ans = ans->next;
	while (ans->value != -1)
	{
		next = ans->next;
		new_value = convert(ans->value, next->value);
		if (compress_cand(new_value) && diff(ans->value, next->value) == 1)
		{
			if (new_value != 6)
				ft_dlst_addback(&new_ans, ft_dlst_new(new_value));
			ans = next->next;
		}		
		else
		{
			ft_dlst_addback(&new_ans, ft_dlst_new(ans->value));
			ans = next;
		}
	}
	// printf("anssize is %d\n", ft_dlst_size(ans));
	// printf("new_anssize is %d\n", ft_dlst_size(new_ans));
	while (ans->value != -1)
		ans = ans->next;
	// ft_dlst_clear(&ans); // 要修正
	return (new_ans);
}
