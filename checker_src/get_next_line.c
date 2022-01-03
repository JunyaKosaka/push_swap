/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 14:36:53 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/03 16:48:22 by jkosaka          ###   ########.fr       */
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

static void	*free_all(char **s1, char **s2)
{
	if (s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (NULL);
}

static char	*join_words(char **s1, const char *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	if (!(*s1) || !s2)
		return (free_one(s1));
	s1_len = ft_strlen(*s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	ret = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!ret)
		return (free_one(s1));
	ft_strlcpy(ret, *s1, s1_len + 1);
	ft_strlcpy(ret + s1_len, s2, total_len + 1);
	free_one(s1);
	return (ret);
}

static char	*get_one_line(char **save, size_t len)
{
	char	*ret;
	char	*temp;

	if (!len || !(*save))
		return (free_one(save));
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (free_one(save));
	ft_strlcpy(ret, *save, len + 1);
	temp = NULL;
	if (*((*save) + len))
		temp = ft_strdup((*save) + len);
	free(*save);
	*save = temp;
	return (ret);
}

static char	*init_save(char *s)
{
	if (!s)
		s = ft_strdup("");
	return (s);
}

char	*get_next_line(t_info *info)
{
	static char	*save = NULL;
	char		*buff;
	ssize_t		read_bytes;

	buff = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buff)
		return (free_all(&save, &buff));
	save = init_save(save);
	read_bytes = 1;
	while (read_bytes && !ft_strchr(save, '\n'))
	{
		read_bytes = read(STDIN, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free_all(&save, &buff);
			exit(free_all_info(info, TRUE));
		}
		buff[read_bytes] = '\0';
		save = join_words(&save, buff);
		if (!save)
			return (free_one(&buff));
	}
	free_one(&buff);
	if (!read_bytes)
		return (get_one_line(&save, ft_strlen(save)));
	return (get_one_line(&save, ft_strchr(save, '\n') - save + 1));
}

// int	main(void)
// {
// 	int		fd;
// 	char	*buff;

// 	if ((fd = open("sample1.txt", O_RDONLY)) == -1)
// 	{
// 		printf("fopen error(%s)\n", strerror(errno));
// 		return (0);
// 	}
// 	while (1)
// 	{
// 		buff = get_next_line(fd);
// 		printf("answer:%s", buff);
// 		if (!buff)
// 			break ;
// 		free(buff);
// 	}
// 	if (buff)
// 		free(buff);
// 	close(fd);
// 	return (0);
// }
