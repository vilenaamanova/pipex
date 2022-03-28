/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:29:56 by ncathy            #+#    #+#             */
/*   Updated: 2022/03/14 21:29:56 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_envp_path(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*get_path(char *cmd_args, char **envp)
{
	char	**paths;
	char	*path_part;
	char	*cmd_path;
	int		j;

	j = 0;
	paths = get_envp_path(envp);
	while (paths[j])
	{
		path_part = ft_strjoin(paths[j], "/");
		cmd_path = ft_strjoin(path_part, cmd_args);
		free(path_part);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		else
			free(cmd_path);
		j++;
	}
	free_arr(paths);
	return (NULL);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
