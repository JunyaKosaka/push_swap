/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:46:52 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/01 00:52:16 by jkosaka          ###   ########.fr       */
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

int	main()
{
	int		i;
	int		trial = 1;
	long	result = 0;
	int		len = 10;
	int		max = 0;
	int		min = INT_MAX;

	i = 0;
	srand(time(NULL));
	while (i < trial)
	{
		int *arr = create_random_arr(len);
		int temp = ps_sort(len, &arr);
		if (temp > max)
			max = temp;
		if (temp < min)
			min = temp;
		result += temp;
		free(arr);
		arr = NULL;
		i++;
	}
	printf("average is %ld\n", result / trial);
	printf("max is %d\n", max);
	printf("min is %d\n", min);
	
	printf("trial is %d\n", trial);
	printf("len is %d\n", len);
	// system("leaks push_swap");
	return (0);
}
