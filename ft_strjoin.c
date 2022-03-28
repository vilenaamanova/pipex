/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:08:48 by ncathy            #+#    #+#             */
/*   Updated: 2022/03/26 10:26:29 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*sum;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		sum = (char *)malloc(sizeof(char)
				* (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (sum == NULL)
			return (NULL);
		while (i < ft_strlen(s1))
			sum[i++] = s1[j++];
		j = 0;
		while (i < (ft_strlen(s2) + ft_strlen(s1)))
			sum[i++] = s2[j++];
		sum[i] = '\0';
		return (sum);
	}
	return (NULL);
}
