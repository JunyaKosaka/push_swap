/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:59:56 by jkosaka           #+#    #+#             */
/*   Updated: 2021/10/19 15:02:31 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**rec(char **container, char const *s, char c, size_t ind)
{
	char const	*head;

	while (*s && *s == c)
		s++;
	if (!(*s))
		return (container);
	head = s;
	while (*s && *s != c)
		s++;
	head = ft_substr(head, 0, s - head);
	if (!head)
		return (NULL);
	container = rec(container, s, c, ind + 1);
	if (!container)
	{
		free((void *)head);
		return (NULL);
	}
	container[ind] = (char *)head;
	return (container);
}

static size_t	word_count(char const *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			ret++;
		s++;
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**ret;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	ret = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ret)
		return (NULL);
	ret[words] = NULL;
	ret = rec(ret, s, c, 0);
	if (!ret)
		free(ret);
	return (ret);
}

// #include <stdio.h>

// static void	print_s(char **s)
// {
// 	while (*s)
// 	{
// 		printf("%s\n", *s);
// 		s++;
// 	}
// 	printf("-----\n");
// }

// int	main(void)
// {
// 	char	s[10][30] = {"aa|b||ccc|", " a   b c", "\0aa\0b", "|||||"};
// 	char	set[10] = {"| \0|"};
// 	char	**t;
// 	int		i = -1;

// 	while (++i < 4)
// 	{
// 		t = ft_split(s[i], set[i]);
// 		print_s(t);
// 	}
// 	printf("Done\n");
// 	return (0);
// }
