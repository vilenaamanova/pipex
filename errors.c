/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 09:08:52 by ncathy            #+#    #+#             */
/*   Updated: 2022/03/26 18:15:31 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_mes1(char *error, char *argument)
{
	write(2, error, ft_strlen(error));
	write(2, argument, ft_strlen(argument));
	write(2, "\n", 1);
	exit(1);
}

void	error_mes2(char *error)
{
	write(2, error, ft_strlen(error));
	exit(1);
}

void	invalid_num(void)
{
	write(2, "Incorrect number of arguments!\n", 32);
	write(1, "Ex: ./pipex <filename1> <cmd1> <cmd2> <filename2>\n", 50);
	exit(1);
}
