/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:15:35 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/10 14:06:23 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/** @brief Start pipex finding heredoc
 * 
 *  @details find heredoc, initialize pipefd and fork first child.
 * 
 * @param pipex pipex structure
 * @param fd file descriptor
 * 
 * @return pid of the fork
*/
static int	start(t_pipex *pipex, int *fd)
{
	int	pid;

	find_here_doc(pipex, fd);
	if (pipe(pipex->pipefd) == -1)
		perror_msg("Pipe error");
	pid = fork();
	if (pid == -1)
		perror_msg("Fork error");
	return (pid);
}

/** @details depending on pid, call the corresponding function for
 *  each process
*/
void	start_pipex(t_pipex *pipex)
{
	pid_t	pid;
	int		fd;

	pid = start(pipex, &fd);
	if (pid == 0)
	{
		if (fd < 0)
			fd = open(pipex->argv[0], O_RDONLY);
		first_child(pipex, fd);
	}
	if (fd > 0)
		close(fd);
	close(pipex->pipefd[1]);
	pipex->idx++;
	middle_loop(pipex);
	pid = fork();
	if (pid == -1)
		perror_msg("Fork error");
	else if (pid == 0)
		last_child(pipex);
	else if (pid > 0)
		parent(pipex->pipefd, pid);
}

/** @details close read end of pipe, wait till all processes are finished.
 *  Exit program with status.
*/
void	parent(int pipefd[2], pid_t pid)
{
	int	status;
	int	aux;
	int	waited;

	close(pipefd[0]);
	while (1)
	{
		waited = waitpid(-1, &aux, 0);
		if (waited == -1)
			break ;
		if (waited == pid)
			status = aux;
	}
	status = (status >> 8) & 0x0000ff;
	exit(status);
}

/** @details for each needed children, create a pipe and a fork and increment
 *  pipex index.
*/
void	middle_loop(t_pipex *pipex)
{
	int		n_pipefd[2];
	pid_t	pid;

	while (pipex->idx < pipex->argc - 2)
	{
		if (pipe(n_pipefd) == -1)
			perror_msg("Pipe error");
		pid = fork();
		if (pid == -1)
			perror_msg("Fork error");
		else if (pid == 0)
			middle_child(n_pipefd, pipex->pipefd[0], pipex);
		close(pipex->pipefd[0]);
		pipex->pipefd[0] = n_pipefd[0];
		close(n_pipefd[1]);
		pipex->idx++;
	}
}
