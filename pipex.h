/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:06:13 by salustianos       #+#    #+#             */
/*   Updated: 2022/05/16 12:17:27 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include <sys/stat.h>

void	ft_path(char *cmd, char *envp[], char **f_path);
void	ft_free_arg(char **matrix);
char	**separate_arguments(char *argv);
void	check_argv(int argc);
void	check_fd(int fd, char *file);
void	check_file(int fd, char *file);
void	number_argv(int argc);
char	**ft_split(const char *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif