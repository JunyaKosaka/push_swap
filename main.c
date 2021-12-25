/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:46:52 by jkosaka           #+#    #+#             */
/*   Updated: 2021/12/25 20:14:43 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

static int	*create_random_arr(int n)
{
	int	j;
	int	*arr;
	int	t;

	arr = (int *)malloc(sizeof(int) * n);
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

// 本番用
int	main(int argc, char *argv[])
{
	push_swap(argc, argv);
	return (0);
}

// int	main()
// {
// 	int		i;
// 	int		trial = 1;
// 	long	result;
// 	int		len = 10;

// 	i = 0;
// 	result = 0;
// 	srand(time(NULL));
// 	while (i < trial)
// 	{
// 		int *arr = create_random_arr(len);
// 		result += solve(len, arr);
// 		i++;
// 	}
// 	// printf("average is %ld\n", result / trial);
// 	// printf("trial is %d\n", trial);
// 	// printf("len is %d\n", len);
// 	return (0);
// }
