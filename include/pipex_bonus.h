/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:30:52 by ejuarros          #+#    #+#             */
/*   Updated: 2024/04/23 11:28:30 by ejuarros         ###   ########.fr       */
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

void	start_pipex(int argc, char **argv, char **env);

void	parent(int pipefd[2], pid_t pid);
void	firstChild(int pipefd[2], char *argv, int fd, char **env);
void    middleChild(int fdW[2], int fdR, char *argv, char **env);
void	lastChild(int pipefd[2], char **argv, char **env);

char	*get_path(char **env, char *arg);
char	*find_path(char **path, char *arg);
void	perror_msg(char *msg);

int     here_doc(char *end);

#endif