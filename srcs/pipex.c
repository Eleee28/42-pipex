/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:15:35 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/10 13:40:28 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/** @details Whenever an error arises print error and exit
 * 		- create the pipe for communication
 * 		- create the fork for child1
 * 		- create the fork for child2
 * 
 * 		pipefd[0] --> read end
 * 		pipefd[1] --> write end
 */
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

/** @details close all pipefds and wait for both childs to end.
 *  Set status to the one of the last child.
 * 	 Operation same as WEXITSTATUS(status)
 */
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

/** @brief duplicate file descriptors safely
 * 	
 * 	@details duplicate and close fds. Handle all possible errors.
 * 
 * 	@param in_fd input file descriptor
 *  @param out_fd output file descriptor
*/
static void	dup_fds(int in_fd, int out_fd)
{
	int	error;

	if (dup2(in_fd, STDIN_FILENO) == -1)
	{
		error = errno;
		close(in_fd);
		close(out_fd);
		errno = error;
		perror_msg("Dup2 error");
	}
	close(in_fd);
	if (dup2(out_fd, STDOUT_FILENO) == -1)
	{
		error = errno;
		close(out_fd);
		errno = error;
		perror_msg("Dup2 error");
	}
	close(out_fd);
}

/** @details child 1 is only going to write on the pipe, so we close the
 *  read end. We split argv using spaces as delimiter and obtain the path
 *  When we have all the info required, execute the command using execve.
 */
void	child_1(int pipefd[2], char **argv, char **env)
{
	char	*path;
	int		fd;
	char	**arg;
	int		error;

	close(pipefd[0]);
	arg = ft_split(argv[1], ' ');
	if (ft_strchr(argv[1], '/') != NULL)
		path = ft_strdup(arg[0]);
	else
		path = get_path(env, arg[0]);
	fd = open(argv[0], O_RDONLY);
	if (fd < 0 || !path)
	{
		error = errno;
		close(pipefd[1]);
		if (fd > 0)
			close(fd);
		errno = error;
		perror_msg("Error");
	}
	dup_fds(fd, pipefd[1]);
	execve(path, arg, env);
	perror_msg("Execve error");
}

/** @details child 2 is only going to read from the pipe, so we close the
 *  write end. We split argv using spaces as delimiter and obtain the path
 *  When we have all the info required, execute the command using execve.
 */
void	child_2(int pipefd[2], char **argv, char **env)
{
	char	*path;
	int		fd;
	char	**arg;
	int		error;

	close(pipefd[1]);
	arg = ft_split(argv[2], ' ');
	if (ft_strchr(argv[2], '/') != NULL)
		path = ft_strdup(arg[0]);
	else
		path = get_path(env, arg[0]);
	fd = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0 || !path)
	{
		error = errno;
		close(pipefd[0]);
		if (fd > 0)
			close(fd);
		errno = error;
		perror_msg("Error");
	}
	dup_fds(pipefd[0], fd);
	execve(path, arg, env);
	perror_msg("Execve error");
}
