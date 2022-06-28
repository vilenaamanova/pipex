/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limiter_part_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:31:13 by ncathy            #+#    #+#             */
/*   Updated: 2022/06/27 09:21:30 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	limiter(char *cmd_line_lim)
{
	int		fd[2];
	pid_t	pid;
	char	*limiter;

	if (pipe(fd) < 0)
		error_mes2(ERROR_PIPE);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		limiter = get_next_line(0);
		while (limiter)
		{
			if (ft_strncmp(limiter, cmd_line_lim, ft_strlen(cmd_line_lim)) == 0)
				exit (0);
			free(limiter);
			limiter = get_next_line(0);
		}
	}
	close(fd[1]);
	waitpid(pid, NULL, 0);
}
