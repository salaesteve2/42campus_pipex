/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:48:10 by salustianos       #+#    #+#             */
/*   Updated: 2022/05/17 09:38:13 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*is_path(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i]);
		i++;
	}
	return (NULL);
}

void	ft_path(char *command, char *envp[], char **fd_path)
{
	char	**paths;
	char	*path;
	char	*commands_path;
	int		i;

	i = 0;
	paths = ft_split(ft_strchr(is_path(envp), '/'), ':');
	*fd_path = NULL;
	if (!paths)
		return ;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		commands_path = ft_strjoin(path, command);
		free(path);
		if (access(commands_path, 0) == 0)
		{
			*fd_path = commands_path;
			ft_free_arg(paths);
			return ;
		}
		free(commands_path);
		i++;
	}
	ft_free_arg(paths);
}

char	**separate_arguments(char *argv)
{
	char	**arguments;

	arguments = ft_split(argv, ' ');
	return (arguments);
}
