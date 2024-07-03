/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:30:52 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/03 12:42:55 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../library/library.h"

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**env;
	int		pipefd[2];
}			t_pipex;

void	start_pipex(char **argv, char **env);

void	parent(int pipefd[2], pid_t pids[2]);
void	child_1(int pipefd[2], char **argv, char **env);
void	child_2(int pipefd[2], char **argv, char **env);

char	*get_path(char **env, char *arg);
char	*find_path(char **path, char *arg);
void	perror_msg(char *msg);

#endif