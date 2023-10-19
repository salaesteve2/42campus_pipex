/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:05:48 by salustianos       #+#    #+#             */
/*   Updated: 2022/05/17 09:48:21 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_father(int *fd, char **argv, char **envp)
{
	int		fd_file;
	char	*path;
	char	**arguments;
	int		process;

	close(fd[0]);
	fd_file = open(argv[1], O_RDONLY);
	check_file(fd_file, argv[1]);
	dup2(fd_file, 0);
	close(fd_file);
	dup2(fd[1], 1);
	close(fd[1]);
	arguments = separate_arguments(argv[2]);
	ft_path(arguments[0], envp, &path);
	process = execve(path, arguments, envp);
	if (process == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(arguments[0], 2);
		ft_free_arg(arguments);
		free(path);
		exit(0);
	}
}

static void	ft_son(int *fd, char **argv, char **envp)
{
	int		fd_file;
	char	*path;
	char	**arguments;
	int		process;

	close(fd[1]);
	fd_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND,
			S_IRWXU);
	check_file(fd_file, argv[4]);
	dup2(fd_file, 1);
	close(fd_file);
	dup2(fd[0], 0);
	close(fd[0]);
	arguments = separate_arguments(argv[3]);
	ft_path(arguments[0], envp, &path);
	process = execve(path, arguments, envp);
	if (process == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(arguments[0], 2);
		ft_free_arg(arguments);
		free(path);
		exit(0);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	int		fd[2];

	number_argv(argc);
	pipe(fd);
	pid = fork();
	if (pid == -1)
		perror("Error");
	if (pid == 0)
		ft_father(fd, argv, envp);
	else
	{
		pid = fork();
		if (pid == -1)
			perror("Error");
		if (pid == 0)
			ft_son(fd, argv, envp);
		else
		{
			close(fd[0]);
			close(fd[1]);
		}
	}
	waitpid(pid, NULL, 0);
	return (0);
}
