/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:21:52 by glaverdu          #+#    #+#             */
/*   Updated: 2021/09/28 10:29:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	temp_print_error(void)
{
	printf("parse error, usage : file1 cmd1 cmd2 file2.\n");
	return (1);
}

int	check_return_value(int i, int pid2, int pid1)
{
	int	status;

	status = 0;
	waitpid(pid1, &status, 0);
	i = 0;
	if (WEXITSTATUS(status))
		i = WEXITSTATUS(status);
	if (i != 0)
		return (i);
	waitpid(pid2, &status, 0);
	if (WEXITSTATUS(status))
		i = WEXITSTATUS(status);
	if (i != 0)
		return (i);
	return (0);
}

int	temp_pid1(int *fd, char **argv1, int fdFile)
{
	dup2(fd[1], STDOUT_FILENO);
	dup2(fdFile, STDIN_FILENO);
	close(fd[1]);
	close(fdFile);
	close(fd[0]);
	if (access(argv1[0], F_OK) == 0)
		execve(argv1[0], argv1, NULL);
	return (0);
}

int	temp_pid2(int *fd, char **argv2, int fdFile2)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(fdFile2, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	if (access(argv2[0], F_OK) == 0)
		execve(argv2[0], argv2, NULL);
	return (0);
}

int	try_to_cut(char **argv1, char **argv2, int i, int *tab_fd)
{
	int	pid1[2];
	int	fd[2];

	if ((i == 1 || i == 127) && access(argv1[0], F_OK) != 0)
		return (i);
	pipe(fd);
	pid1[0] = fork();
	if (pid1[0] < 0)
		return (2);
	if (pid1[0] == 0)
		return (temp_pid1(fd, argv1, tab_fd[0]));
	if (i == 127 || i == 1)
		return (i);
	pid1[1] = fork();
	if (pid1[1] < 0)
		return (3);
	if (pid1[1] == 0)
		return (temp_pid2(fd, argv2, tab_fd[1]));
	close (fd[1]);
	close (fd[0]);
	if (check_return_value(i, pid1[1], pid1[0]))
		return (check_return_value(i, pid1[1], pid1[0]));
	if (tab_fd[0] == -1 && access(argv1[0], F_OK) == 0)
		return (1);
	return (0);
}
