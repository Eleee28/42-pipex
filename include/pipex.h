/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:30:52 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/10 13:25:42 by ejuarros         ###   ########.fr       */
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

/********************************************************/
/*					   PIPEX							*/
/********************************************************/

/** @brief Start pipex function
 *  
 *  @param argv command line arguments
 *  @param env environment variables
*/
void	start_pipex(char **argv, char **env);

/** @brief parent routine
 * 
 *  @param pipefd pipe file descriptors
 *  @param pids pids (process IDs) of the children
*/
void	parent(int pipefd[2], pid_t pids[2]);

/** @brief child1 routine
 * 
 *  @param pipefd pipe file descriptor
 *  @param argv arguments
 *  @param env environment variables
*/
void	child_1(int pipefd[2], char **argv, char **env);

/** @brief child2 routine
 * 
 *  @param pipefd pipe file descriptor
 *  @param argv arguments
 *  @param env environment variables
*/
void	child_2(int pipefd[2], char **argv, char **env);

/********************************************************/
/*					    UTILS							*/
/********************************************************/

/** @brief get path from environment variables
 * 
 *  @param env environment variables
 *  @param arg argument
 * 
 *  @return path
*/
char	*get_path(char **env, char *arg);

/** @brief find path on system
 * 
 *  @param path directory paths
 *  @param arg argument
 * 
 *  @return path
*/
char	*find_path(char **path, char *arg);

/** @brief print error message and exit
 * 
 *  @param msg error message to print
*/
void	perror_msg(char *msg);

#endif