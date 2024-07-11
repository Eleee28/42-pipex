/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:30:52 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/11 10:50:03 by ejuarros         ###   ########.fr       */
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

/** @brief pipes structure
 * 
 * @param argc argument count
 * @param argv argument values
 * @param env environment variables
 * @param heredoc flag to mark if there is a heredoc
 * @param idx argument index
 * @param pipefd pipe file descriptors
*/
typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**env;
	int		heredoc;
	int		idx;
	int		pipefd[2];
}			t_pipex;

/********************************************************/
/*						   PIPEX						*/
/********************************************************/

/** @brief start pipex function
 * 
 * @param pipex pipex structure
*/
void	start_pipex(t_pipex *pipex);

/** @brief parent routine
 * 
 * @param pipefd pipe file descriptors
 * @param pid pid of last child
*/
void	parent(int pipefd[2], pid_t pid);

/** @brief loop for middle children
 * 
 * @param pipex pipex structure
*/
void	middle_loop(t_pipex *pipex);

/********************************************************/
/*					  		 CHILDS						*/
/********************************************************/

/** @brief First child routine
 * 
 * @param pipex pipex structure
 * @param fd file descriptor
*/
void	first_child(t_pipex *pipex, int fd);

/** @brief Middle child routine
 * 
 * @param fdW write file descriptor
 * @param fdR read file descriptor
 * @param pipex pipex structure
*/
void	middle_child(int fdW[2], int fdR, t_pipex *pipex);

/** @brief Last child routine
 * 
 * @param pipex pipex structure
*/
void	last_child(t_pipex *pipex);

/********************************************************/
/*					 	  	UTILS						*/
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

/********************************************************/
/*					 	  HEREDOC						*/
/********************************************************/

/** @brief Heredoc action 
 * 
 *  @param end delimiter
 * 
 *  @return pipe file descriptor
*/
int		here_doc(char *end);

/** @brief Find here doc
 * 
 *  @param pipex pipex structure
 *  @param fd file descriptor
*/
void	find_here_doc(t_pipex *pipex, int *fd);

#endif