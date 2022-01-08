/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:46:52 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/09 01:56:04 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc > ARGMAX)
		exit(error_handler());
	push_swap(argc, argv);
	system("leaks push_swap");
	return (0);
}

// #include <time.h>
// static int	*create_random_arr(int n)
// {
// 	int	j;
// 	int	*arr;
// 	int	t;

// 	arr = (int *)malloc(sizeof(int) * n);
// 	if (!arr)
// 		return (NULL);
// 	j = 0;
// 	for (int i = 0; i < n; i++) arr[j++] = i;
// 	for (int i = n-1; i > 0; i--) {
// 		j = (rand() % (i));
// 		t = arr[i];
// 		arr[i] = arr[j];
// 		arr[j] = t;
// 	}
// 	return (arr);
// }

// static int	ps_test_sort(int len, int *arr)
// {
// 	t_info	info;
// 	int		result;

// 	info.arr = arr;
// 	info.total_len = len;
// 	init_stack(&info);
// 	if (is_sorted(info.total_len, info.arr))
// 	{
// 		free_all_info(&info, false);
// 		return (0);
// 	}
// 	result = ps_sort(&info);
// 	free_all_info(&info, false);
// 	if (result == -1)
// 		return (error_handler());
// 	return (result);
// }

// int	main()
// {
// 	int		i;
// 	int		trial = 200;
// 	long	result = 0;
// 	int		len = 500;
// 	int		max = 0;
// 	int		min = INT_MAX;

// 	i = 0;
// 	srand(time(NULL));
// 	while (i < trial)
// 	{
// 		int *arr = create_random_arr(len);
// 		int temp = ps_test_sort(len, arr);
// 		if (temp > max)
// 			max = temp;
// 		if (temp < min)
// 			min = temp;
// 		result += temp;
// 		i++;
// 	}
// 	// printf("result is %ld\n", result);
// 	printf("average is \x1b[35m[\033[m%ld\x1b[35m]\033[m\n", result / trial);
// 	printf("max is %d\n", max);
// 	printf("min is %d\n", min);
	
// 	printf("trial is %d\n", trial);
// 	printf("len is %d\n", len);
// 	// system("leaks push_swap");
// 	return (0);
// }
