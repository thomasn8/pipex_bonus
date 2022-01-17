/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:41:11 by tnanchen          #+#    #+#             */
/*   Updated: 2022/01/17 15:06:43 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// read input from terminal STDIN 
// until a line containing ONLY the delimiter is seen 
// (source: BASH man)
static void	read_terminal_lines(char *limiter, int *pipefd)
{
	char	*line;
	char	*limiter_nl;
	int		len;

	limiter_nl = ft_strjoin(limiter, "\n");
	len = ft_strlen(limiter) + 1;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strncmp(line, limiter_nl, len) == 0
			|| ft_strncmp(line, limiter, len) == 0)
		{
			free(limiter_nl);
			free(line);
			exit(EXIT_SUCCESS);
		}
		write(pipefd[1], line, ft_strlen(line));
		free(line);
	}
}

static void	pipe_terminal(char *limiter)
{
	pid_t	child;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		exit(UNPREDICTABLE_ERROR);
	child = fork();
	if (child == -1)
		exit(UNPREDICTABLE_ERROR);
	if (child == 0)
	{
		if (close(pipefd[0]) == -1)
			exit(UNPREDICTABLE_ERROR);
		read_terminal_lines(limiter, pipefd);
	}
	else
	{
		if (dup2(pipefd[0], STDIN_FILENO) == -1 || close(pipefd[1]) == -1)
			exit(UNPREDICTABLE_ERROR);
		waitpid(child, NULL, 0);
	}
}

static void	pipe_process(char *cmd, char **envp)
{
	pid_t	child;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		exit(UNPREDICTABLE_ERROR);
	child = fork();
	if (child == -1)
		exit(UNPREDICTABLE_ERROR);
	if (child == 0)
	{
		if (dup2(pipefd[1], STDOUT_FILENO) == -1 || close(pipefd[0]))
			exit(UNPREDICTABLE_ERROR);
		execute_cmd(cmd, envp);
	}
	else
	{
		if (dup2(pipefd[0], STDIN_FILENO) == -1 || close(pipefd[1]))
			exit(UNPREDICTABLE_ERROR);
		waitpid(child, NULL, 0);
	}
}

static int	count_commands(int ac, int files)
{
	if (files == 1)
		return (ac - 4);
	return (ac - 3);
}

int	main(int ac, char **av, char **envp)
{
	int		files;
	t_file	infile;
	t_file	outfile;
	int		i;
	int		cmd_count;

	files = here_doc(ac, av, &infile, &outfile);
	get_files_fd(files, &infile, &outfile);
	cmd_count = count_commands(ac, files);
	if (files == 1)
		pipe_terminal(av[2]);
	else
	{
		if (dup2(infile.fd, STDIN_FILENO) == -1)
			exit(UNPREDICTABLE_ERROR);
	}
	i = 0;
	if (files == 1)
		i++;
	while (--cmd_count)
		pipe_process(av[2 + i++], envp);
	if (dup2(outfile.fd, STDOUT_FILENO) == -1)
		exit(UNPREDICTABLE_ERROR);
	execute_cmd(av[ac - 2], envp);
	return (0);
}
