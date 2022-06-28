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

void	child_bonus(char *cmd, char **envp)
{
	char	**cmd_args;
	char	*path;

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

void	*pipex_bonus(char *argv1, char **envp)
{
	int		fd[2];
	pid_t	pid_frst;

	if (pipe(fd) < 0)
		error_mes2(ERROR_PIPE);
	pid_frst = fork();
	if (pid_frst == -1)
		error_mes2(ERROR_FORK);
	if (pid_frst == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		child_bonus(argv1, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid_frst, NULL, 0);
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	fd1;
	int	fd2;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			fd2 = open_file(argc, argv, 3);
			limiter(argv[2]);
		}
		else
		{
			i = 2;
			fd1 = open_file(argc, argv, 1);
			fd2 = open_file(argc, argv, 2);
			dup2(fd1, 0);
		}
		while (i < argc - 2)
			pipex_bonus(argv[i++], envp);
		dup2(fd2, 1);
		child_bonus(argv[argc - 2], envp);
	}
	invalid_num();
}
