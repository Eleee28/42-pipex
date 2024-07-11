/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:48:48 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/11 10:43:59 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

/** @details Create a pipe and read until the delimiter (end) is found
 *  writing the read info on the pipe.
*/
int	here_doc(char *end)
{
	char	*line;
	int		pipefd[2];

	end = ft_strjoin(end, "\n");
	if (pipe(pipefd) == -1)
		perror_msg("Pipe error");
	line = get_next_line(0);
	while (line && ft_strncmp(line, end, ft_strlen(line)) != 0)
	{
		write(pipefd[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	if (line)
		free(line);
	free(end);
	close(pipefd[1]);
	return (pipefd[0]);
}

/** @details If there is a here doc perform its action and turn the flag to 1 
*/
void	find_here_doc(t_pipex *pipex, int *fd)
{
	pipex->heredoc = 0;
	pipex->idx = 1;
	(*fd) = -1;
	if (ft_strncmp(pipex->argv[0], "here_doc", ft_strlen(pipex->argv[0])) == 0)
	{
		(*fd) = here_doc(pipex->argv[1]);
		pipex->heredoc = 1;
		(pipex->argv)++;
		(pipex->argc)--;
	}
}
