/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:47:50 by jkosaka           #+#    #+#             */
/*   Updated: 2022/01/03 19:49:42 by jkosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define BUFFER_SIZE 256
# include "./utils.h"

/*   checker_src   */
int		checker(int argc, char *argv[]);
char	*get_next_line(t_info *info);
void	*free_one(char **s);
void	*free_all(char **s1, char **s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif // CHECKER_H
