/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:15:35 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/03 12:54:27 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	start_pipex(char **argv, char **env)
{
	int		pipefd[2];
	pid_t	pids[2];

	if (pipe(pipefd) == -1)
		perror_msg("Pipe error");
	pids[0] = fork();
	if (pids[0] == -1)
		perror_msg("Fork error");
	else if (pids[0] == 0)
		child_1(pipefd, argv, env);
	pids[1] = fork();
	if (pids[1] == -1)
		perror_msg("Fork error");
	else if (pids[1] == 0)
		child_2(pipefd, argv, env);
	else if (pids[0] > 0)
		parent(pipefd, pids);
}

void	parent(int pipefd[2], pid_t pids[2])
{
	int	status;

	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pids[0], &status, 0);
	waitpid(pids[1], &status, 0);
	status = (status >> 8) & 0x0000ff;
	exit(status);
}

void	child_1(int pipefd[2], char **argv, char **env)
{
	char	*c;
	char	*path;
	int		fd;
	char	**arg;

	close(pipefd[0]);
	c = ft_strchr(argv[1], '/');
	arg = ft_split(argv[1], ' ');
	if (c != NULL)
		path = ft_strdup(argv[1]);
	else
		path = get_path(env, arg[0]);
	fd = open(argv[0], O_RDONLY);
	if (fd < 0 || !path)
	{
		close(pipefd[1]);
		perror_msg("Error");
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		perror_msg("Dup2 error");
	close(fd);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		perror_msg("Dup2 error");
	close(pipefd[1]);
	execve(path, arg, env);
	perror_msg("Execve error");
}

void	child_2(int pipefd[2], char **argv, char **env)
{
	char	*c;
	char	*path;
	int		fd;
	char	**arg;

	close(pipefd[1]);
	c = ft_strchr(argv[2], '/');
	arg = ft_split(argv[2], ' ');
	if (c != NULL)
		path = ft_strdup(argv[2]);
	else
		path = get_path(env, arg[0]);
	fd = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0 || !path)
	{
		close(pipefd[0]);
		perror_msg("Error");
	}
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		perror_msg("Dup2 error");
	close(pipefd[0]);
	if (dup2(fd, STDOUT_FILENO) == -1)
		perror_msg("Dup2 error");
	close(fd);
	execve(path, arg, env);
	perror_msg("Execve error");
}
