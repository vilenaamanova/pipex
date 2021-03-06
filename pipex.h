/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncathy <ncathy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:30:34 by ncathy            #+#    #+#             */
/*   Updated: 2022/01/19 15:30:34 by ncathy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>

# define ERROR_COMMAND "command not found: "
# define ERROR_FILE "no such file or directory: "
# define ERROR_PERMISSION "permission denied: "
# define ERROR_PIPE "Pipe error\n"
# define ERROR_FORK "Fork error\n"
# define ERROR_OPEN "Open error\n"
# define ERROR_EXECVE "Execve error\n"

# define BUFFER_SIZE 10

/* libft */

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* path */

char	*get_path(char *cmd_args, char **envp);
char	**get_envp_path(char **envp);

/* pipex */

void	first_child_process(int fd1, int *fd, char *cmd, char **envp);
void	second_child_process(int fd2, int *fd, char *cmd, char **envp);
void	parent_process(int fd1, int fd2);
void	pipex(int fd1, int fd2, char **argv, char **envp);

/* pipex bonus */
void	*pipex_bonus(char *argv1, char **envp);
void	child_bonus(char *cmd, char **envp);

/* error */

void	invalid_num(void);
void	error_mes1(char *error, char *argument);
void	error_mes2(char *error);

/* utils */

void	free_arr(char **arr);
int		open_file(int argc, char **argv, int id);

/* bonus */

void	limiter(char *cmd_line_lim);

/* get_next_line */

char	*get_next_line(int fd);
char	*ft_strjoin_mod(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

int		main(int argc, char **argv, char **envp);

#endif
