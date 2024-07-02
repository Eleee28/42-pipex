/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:48:48 by ejuarros          #+#    #+#             */
/*   Updated: 2024/04/23 08:44:46 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int    here_doc(char *end)
{
    char    *line;
    int     pipefd[2];

    end = ft_strjoin(end, "\n");
    
    if (pipe(pipefd) == -1)     // pipefd[0] = read, pipefd[1] = write
        perror_msg("Pipe error");
    //close(pipefd[0]);
    line = get_next_line(0);
    while (line && ft_strncmp(line, end, ft_strlen(line)) != 0)
    {
        //ft_putendl_fd(line, 1); // instead write in pipefd[1]
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
