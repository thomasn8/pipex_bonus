/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:43:04 by tnanchen          #+#    #+#             */
/*   Updated: 2022/01/17 15:08:31 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	usage(void)
{
	ft_putstr_fd("Usage :\n", 2);
	ft_putstr_fd("./pipex ['here_doc' LIMITER]/[input_file] ", 2);
	ft_putstr_fd("cmd1 cmd2 [...] [cmdn] output_file\n", 2);
	exit(UNPREDICTABLE_ERROR);
}

int	here_doc(int ac, char **av, t_file *infile, t_file *outfile)
{
	if (ac < 5)
		usage();
	outfile->name = av[ac - 1];
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (ac < 6)
			usage();
		infile->name = NULL;
		return (1);
	}
	infile->name = av[1];
	return (2);
}

static void	permission_error_msg(char *msg, char *file)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(" : ", 2);
	ft_putstr_fd(file, 2);
	ft_putchar_fd('\n', 2);
}

void	get_files_fd(int files, t_file *infile, t_file *outfile)
{
	if (files == 2)
	{
		if (access(infile->name, R_OK) == -1)
		{
			permission_error_msg(strerror(errno), infile->name);
			exit(PERMISSION_ERROR);
		}
		infile->fd = open(infile->name, O_RDONLY);
		if (infile->fd == -1)
			exit(UNPREDICTABLE_ERROR);
	}
	if (access(outfile->name, F_OK) == 0)
	{
		if (access(outfile->name, W_OK) == -1)
		{
			permission_error_msg(strerror(errno), outfile->name);
			exit(PERMISSION_ERROR);
		}
	}
	if (files == HERE_DOC)
		outfile->fd = open(outfile->name, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		outfile->fd = open(outfile->name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile->fd == -1)
		exit(UNPREDICTABLE_ERROR);
}
