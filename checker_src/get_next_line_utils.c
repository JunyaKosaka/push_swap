/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:26:59 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/04 21:33:33 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	*free_one(char **s)
{
	if (s)
	{
		free(*s);
		*s = NULL;
	}
	return (NULL);
}

void	*free_all(char **s1, char **s2)
{
	free_one(s1);
	free_one(s2);
	return (NULL);
}
