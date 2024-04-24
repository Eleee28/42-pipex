/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:30:52 by ejuarros          #+#    #+#             */
/*   Updated: 2024/04/24 10:22:09 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	int		heredoc;
	int		idx;
	int		pipefd[2];
}			t_pipex;

void	start_pipex(t_pipex *pipex);

void	parent(int pipefd[2], pid_t pid);
void	first_child(t_pipex *pipex, int fd);
void	middle_child(int fdW[2], int fdR, t_pipex *pipex);
void	last_child(t_pipex *pipex);
void	middle_loop(t_pipex *pipex);

char	*get_path(char **env, char *arg);
char	*find_path(char **path, char *arg);
void	perror_msg(char *msg);

int		here_doc(char *end);
void	find_here_doc(t_pipex *pipex, int *fd);

#endif