/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:44:23 by tnanchen          #+#    #+#             */
/*   Updated: 2022/01/17 14:43:05 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_path_list(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

static char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*slash;
	int		i;

	i = 0;
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return (cmd);
	paths = get_path_list(envp);
	i = -1;
	while (paths[++i])
	{
		slash = ft_strjoin(paths[i], "/");
		path = ft_strjoin(slash, cmd);
		free(slash);
		if (access(path, F_OK) == 0)
		{
			ft_free_arr(paths);
			return (path);
		}
		free(path);
	}
	ft_free_arr(paths);
	return (0);
}

static void	execution_error(char *cmd)
{
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(cmd, 2);
	write(2, "\n", 1);
	exit (EXEC_ERROR);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	**cmd_arg_list;
	char	*path;

	cmd_arg_list = ft_split(cmd, ' ');
	path = find_path(cmd_arg_list[0], envp);
	if (path == NULL || execve(path, cmd_arg_list, envp) == -1)
	{
		ft_free_arr(cmd_arg_list);
		free(path);
		execution_error(cmd);
	}
}
