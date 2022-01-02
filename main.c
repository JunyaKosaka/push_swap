/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:46:52 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/02 18:45:00 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"
#include <time.h> // delete

// // 本番用
// int	main(int argc, char *argv[])
// {
// 	if (argc > ARGMAX)
// 		exit(error_handler());
// 	else
// 		push_swap(argc, argv);
// 	return (0);
// }

static int	*create_random_arr(int n)
{
	int	j;
	int	*arr;
	int	t;

	arr = (int *)malloc(sizeof(int) * n);
	if (!arr)
		return (NULL);
	j = 0;
	for (int i = 0; i < n; i++) arr[j++] = i;
	for (int i = n-1; i > 0; i--) {
		j = (rand() % (i));
		t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
	}
	return (arr);
}

static int	ps_test_sort(int len, int *arr)
{
	t_info	info;
	int		total_len;
	int		result;

	total_len = len;
	info.arr = arr;
	init_stack(total_len, &info);
	if (is_sorted(total_len, info.arr))
	{
		free_all_info(&info, FALSE);
		return (0);
	}
	result = ps_sort(&info);
	free_all_info(&info, FALSE);
	if (result == -1)
		return (error_handler());
	return (result);
}

int	main()
{
	int		i;
	int		trial = 5;
	long	result = 0;
	int		len = 500;
	int		max = 0;
	int		min = INT_MAX;

	i = 0;
	srand(time(NULL));
	while (i < trial)
	{
		int *arr = create_random_arr(len);
		int temp = ps_test_sort(len, arr);
		if (temp > max)
			max = temp;
		if (temp < min)
			min = temp;
		result += temp;
		i++;
	}
	// printf("result is %ld\n", result);
	printf("average is %ld\n", result / trial);
	printf("max is %d\n", max);
	printf("min is %d\n", min);
	
	printf("trial is %d\n", trial);
	printf("len is %d\n", len);
	// system("leaks push_swap");
	return (0);
}
