/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:15:51 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/11 10:59:35 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

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

/** @details first child is only going to write on the pipe, so we close the
 *  read end. We split argv using spaces as delimiter and obtain the path
 *  When we have all the info required, execute the command using execve.
 */
void	first_child(t_pipex *pipex, int fd)
{
	char	*path;
	char	**arg;
	int		error;

	close(pipex->pipefd[0]);
	arg = ft_split(pipex->argv[pipex->idx], ' ');
	if (ft_strchr(pipex->argv[pipex->idx], '/') != NULL)
		path = ft_strdup(arg[0]);
	else
		path = get_path(pipex->env, arg[0]);
	if (fd < 0 || !path)
	{
		error = errno;
		close(pipex->pipefd[1]);
		if (fd > 0)
			close(fd);
		errno = error;
		perror_msg("Error");
	}
	dup_fds(fd, pipex->pipefd[1]);
	execve(path, arg, pipex->env);
	perror_msg("Execve error");
}

/** @details middle child is going to write on the fdW, so we close the
 *  read end, and it is going to read from the fdR. We split argv using
 *  spaces as delimiter and obtain the path.
 *  When we have all the info required, execute the command using execve.
 */
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
	{
		close(fdW[1]);
		close(fdR);
		perror_msg("Error");
	}
	dup_fds(fdR, fdW[1]);
	execve(path, arg, pipex->env);
	perror_msg("Execve error");
}

/** @brief open file descriptor
 * 
 * @details open the file on a different mode depending on if there is a 
 * heredoc or not
 * 
 * @param pipex pipex structure
 * @param fd file descriptor
*/
static void	fd_open(t_pipex *pipex, int *fd)
{
	if (pipex->heredoc)
		(*fd) = open(pipex->argv[1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		(*fd) = open(pipex->argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
}

/** @details last child is only going to read from the pipe, so we close the
 *  write end. We split argv using spaces as delimiter and obtain the path
 *  When we have all the info required, execute the command using execve.
 */
void	last_child(t_pipex *pipex)
{
	char	*path;
	int		fd;
	char	**arg;
	int		error;

	pipex->argv += pipex->idx;
	arg = ft_split(pipex->argv[0], ' ');
	if (ft_strchr(pipex->argv[0], '/') != NULL)
		path = ft_strdup(arg[0]);
	else
		path = get_path(pipex->env, arg[0]);
	fd_open(pipex, &fd);
	if (fd < 0 || !path)
	{
		error = errno;
		close(pipex->pipefd[0]);
		if (fd > 0)
			close(fd);
		errno = error;
		perror_msg("Error");
	}
	dup_fds(pipex->pipefd[0], fd);
	execve(path, arg, pipex->env);
	perror_msg("Execve error");
}
