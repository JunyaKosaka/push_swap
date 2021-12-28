/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:46:52 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/29 01:49:11 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

// // 本番用
// int	main(int argc, char *argv[])
// {
// 	push_swap(argc, argv);
// 	// system("leaks push_swap");
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
	int		trial = 500;
	long	result;
	int		len = 500; // - 1;
	int		max = 0;

	i = 0;
	result = 0;
	srand(time(NULL));
	while (i < trial)
	{
		int *arr = create_random_arr(len);
		int temp = solve(len, arr);
		if (temp > max)
			max = temp;
		result += temp;
		free(arr);
		arr = NULL;
		i++;
	}
	printf("average is %ld\n", result / trial);
	printf("max is %d\n", max);
	printf("trial is %d\n", trial);
	printf("len is %d\n", len);
	// system("leaks push_swap");
	return (0);
}
