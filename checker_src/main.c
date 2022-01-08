/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:20:59 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/09 01:18:03 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*   checker main   */
int	main(int argc, char *argv[])
{
	if (argc > ARGMAX)
		exit(error_handler());
	else
		checker(argc, argv);
	system("leaks checker");
	return (0);
}
