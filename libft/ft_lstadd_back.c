/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:34:21 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/21 14:08:18 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t_last;

	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		t_last = ft_lstlast(*lst);
		t_last->next = new;
	}
}
