/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:15:51 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/03 12:35:48 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	first_child(t_pipex *pipex, int fd)
{
	char	*path;
	char	**arg;

	close(pipex->pipefd[0]);
	arg = ft_split(pipex->argv[pipex->idx], ' ');
	if (ft_strchr(pipex->argv[pipex->idx], '/') != NULL)
		path = ft_strdup(arg[0]);
	else
		path = get_path(pipex->env, arg[0]);
	if (fd < 0 || !path)
	{
		close(pipex->pipefd[1]);
		perror_msg("Error");
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		perror_msg("Dup2 error");
	close(fd);
	if (dup2(pipex->pipefd[1], STDOUT_FILENO) == -1)
		perror_msg("Dup2 error");
	close(pipex->pipefd[1]);
	execve(path, arg, pipex->env);
	perror_msg("Execve error");
}

void	middle_child(int fdW[2], int fdR, t_pipex *pipex)
{
	char	*path;
	char	**arg;

	close(fdW[0]);
	arg = ft_split(pipex->argv[pipex->idx], ' ');
	if (ft_strchr(pipex->argv[pipex->idx], '/') != NULL)
		path = ft_strdup(arg[0]);
	else
		path = get_path(pipex->env, arg[0]);
	if (!path)
		perror_msg("Error");
	if (dup2(fdR, STDIN_FILENO) == -1)
		perror_msg("Dup2 error");
	close(fdR);
	if (dup2(fdW[1], STDOUT_FILENO) == -1)
		perror_msg("Dup2 error");
	close(fdW[1]);
	execve(path, arg, pipex->env);
	perror_msg("Execve error");
}

void	last_child(t_pipex *pipex)
{
	char	*path;
	int		fd;
	char	**arg;

	pipex->argv += pipex->idx;
	arg = ft_split(pipex->argv[0], ' ');
	if (ft_strchr(pipex->argv[0], '/') != NULL)
		path = ft_strdup(arg[0]);
	else
		path = get_path(pipex->env, arg[0]);
	if (pipex->heredoc)
		fd = open(pipex->argv[1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		fd = open(pipex->argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0 || !path)
	{
		close(pipex->pipefd[0]);
		perror_msg("Error");
	}
	if (dup2(pipex->pipefd[0], STDIN_FILENO) == -1)
		perror_msg("Dup2 error");
	close(pipex->pipefd[0]);
	if (dup2(fd, STDOUT_FILENO) == -1)
		perror_msg("Dup2 error");
	close(fd);
	execve(path, arg, pipex->env);
	perror_msg("Execve error");
}
