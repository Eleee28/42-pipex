/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:15:35 by ejuarros          #+#    #+#             */
/*   Updated: 2024/04/23 14:11:55 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	start_pipex(int argc, char **argv, char **env)
{
	int		o_pipefd[2];
	int		n_pipefd[2];
	pid_t	pid;
	int		fd;
	int		idx;
	int		hereDoc;

	fd = -1;
	hereDoc = 0;
	if (ft_strncmp(argv[0], "here_doc", ft_strlen(argv[0])) == 0)
	{
		fd = here_doc(argv[1]);
		hereDoc = 1;
		argv++;
		argc--;
	}
	idx = 1;
	if (pipe(o_pipefd) == -1)
		perror_msg("Pipe error");
	pid = fork();
	if (pid == -1)
		perror_msg("Fork error");
	else if (pid == 0)
	{
		if (fd < 0)
			fd = open(argv[0], O_RDONLY);
		firstChild(o_pipefd, argv[idx], fd, env);
	}
	close(o_pipefd[1]);
	idx++;
	while (idx < argc - 2)
	{
		if (pipe(n_pipefd) == -1)
			perror_msg("Pipe error");

		pid = fork();
		if (pid == -1)
			perror_msg("Fork error");
		else if (pid == 0)
			middleChild(n_pipefd, o_pipefd[0], argv[idx], env);
		close(o_pipefd[0]);
		o_pipefd[0] = n_pipefd[0];
		close(n_pipefd[1]);
		
		idx++;
	}
	pid = fork();
	//ft_printf("Index: %d\n", idx);
	if (pid == -1)
		perror_msg("Fork error");
	else if (pid == 0)
		lastChild(o_pipefd, &argv[idx], env, hereDoc);
	else if (pid > 0)
		parent(o_pipefd, pid);
}

void	parent(int pipefd[2], pid_t pid)
{
	int	status;
	int	aux;
	int waited;

	close(pipefd[0]);
	while (1)
	{
		waited = waitpid(-1, &aux, 0);
		if (waited == -1)
			break;
		if (waited == pid)
			status = aux;
	}
	status = (status >> 8) & 0x0000ff;
	exit(status);
}

void	firstChild(int pipefd[2], char *argv, int fd, char **env)
{
	char	*c;
	char	*path;
	char	**arg;

	close(pipefd[0]);
	c = ft_strchr(argv, '/');
	arg = ft_split(argv, ' ');
	if (c != NULL)
		path = ft_strdup(arg);
	else
		path = get_path(env, arg[0]);
	if (fd < 0 || !path)
		perror_msg("Error");
	if (dup2(fd, STDIN_FILENO) == -1)
		perror_msg("Dup2 error");
	close(fd);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		perror_msg("Dup2 error");
	close(pipefd[1]);	
	execve(path, arg, env);
	perror_msg("Execve error");
}

void middleChild(int fdW[2], int fdR, char *argv, char **env)
{
	char	*c;
	char	*path;
	char	**arg;

	close(fdW[0]);
	c = ft_strchr(argv, '/');
	arg = ft_split(argv, ' ');
	if (c != NULL)
		path = ft_strdup(arg);
	else
		path = get_path(env, arg[0]);
	if (!path)
		perror_msg("Error");
	if (dup2(fdR, STDIN_FILENO) == -1)
		perror_msg("Dup2 error");
	close(fdR);
	if (dup2(fdW[1], STDOUT_FILENO) == -1)
		perror_msg("Dup2 error");
	close(fdW[1]);
	execve(path, arg, env);
	perror_msg("Execve error");
}

void	lastChild(int pipefd[2], char **argv, char **env, int hereDoc)
{
	char	*c;
	char	*path;
	int		fd;
	char	**arg;
	int		extraMode;

	c = ft_strchr(argv[0], '/');
	arg = ft_split(argv[0], ' ');
	if (c != NULL)
		path = ft_strdup(arg[0]);
	else
		path = get_path(env, arg[0]);
	extraMode = O_TRUNC;
	if (hereDoc)
		extraMode = O_APPEND;
	fd = open(argv[1], O_WRONLY | O_CREAT | extraMode, 0777);
	if (fd < 0 || !path)
		perror_msg("Error");
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		perror_msg("Dup2 error");
	close(pipefd[0]);
	if (dup2(fd, STDOUT_FILENO) == -1)
		perror_msg("Dup2 error");
	close(fd);

	/*________________________________________________________*/

	FILE *file = fopen("debug.txt", "w");
	fprintf(file, "==> Path: [%s]\n==> Arguments:\n", path);

	int index = 0;
	while (arg[index])
		fprintf(file, "\t· [%s]\n", arg[index++]);
	fprintf(file, "\t· NULL\n");
	fclose(file);

	/*________________________________________________________*/


	execve(path, arg, env);
	perror_msg("Execve error");
}
