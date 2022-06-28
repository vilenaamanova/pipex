/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:27:15 by ncathy            #+#    #+#             */
/*   Updated: 2022/01/19 15:27:15 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	first_child_process(int fd1, int *fd, char *cmd, char **envp)
{
	char	**cmd_args;
	char	*path;

	dup2(fd1, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	cmd_args = ft_split(cmd, ' ');
	path = get_path(cmd_args[0], envp);
	if (!path)
	{
		free_arr(cmd_args);
		error_mes1(ERROR_COMMAND, cmd);
	}
	if (execve(path, cmd_args, envp) == -1)
		error_mes2(ERROR_EXECVE);
}

void	second_child_process(int fd2, int *fd, char *cmd, char **envp)
{
	char	**cmd_args;
	char	*path;

	dup2(fd2, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	cmd_args = ft_split(cmd, ' ');
	path = get_path(cmd_args[0], envp);
	if (!path)
	{
		free_arr(cmd_args);
		error_mes1(ERROR_COMMAND, cmd);
	}
	if (execve(path, cmd_args, envp) == -1)
		error_mes2(ERROR_EXECVE);
}

void	parent_process(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

void	pipex(int fd1, int fd2, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid_frst;
	pid_t	pid_scnd;

	if (pipe(fd) < 0)
		error_mes2(ERROR_PIPE);
	pid_frst = fork();
	if (pid_frst == -1)
		error_mes2(ERROR_FORK);
	if (pid_frst == 0)
		first_child_process(fd1, fd, argv[2], envp);
	pid_scnd = fork();
	if (pid_scnd == -1)
		error_mes2(ERROR_FORK);
	if (pid_scnd == 0)
		second_child_process(fd2, fd, argv[3], envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid_frst, NULL, 0);
	waitpid(pid_scnd, NULL, 0);
	parent_process(fd1, fd2);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;

	if (argc == 5)
	{
		fd1 = open(argv[1], O_RDONLY);
		if (fd1 < 0)
			error_mes1(ERROR_FILE, argv[1]);
		fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (fd2 < 0)
			error_mes1(ERROR_PERMISSION, argv[4]);
		pipex(fd1, fd2, argv, envp);
	}
	else
		invalid_num();
	return (0);
}
