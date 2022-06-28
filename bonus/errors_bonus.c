/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 09:08:52 by ncathy            #+#    #+#             */
/*   Updated: 2022/06/23 17:13:15 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
	exit(1);
}
