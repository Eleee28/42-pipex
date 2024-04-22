/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:21:15 by elena             #+#    #+#             */
/*   Updated: 2024/03/20 09:02:59 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

/**
 * @details 
 *  - Correct file descriptors are positive numbers 
 * 		(0 for stdin, 1 for stdout, 2 for stderr)
 * 
 *  - If the BUFFER_SIZE is <= 0 there is nothing to read
 * 
 *  - If read() < 0 it means there has been an error reading from fd 
 * 	(note that reads 0 characters so that it does not advance in the file)
*/
char	*get_next_line(int fd)
{
	static t_line	*list[OPEN_MAX];
	char			*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX
		|| read(fd, 0, 0) < 0)
	{
		free_mem(&list[fd], 0, 0);
		return (0);
	}
	create_list(&list[fd], fd);
	if (!list[fd])
		return (0);
	line = read_line(list[fd]);
	update_list(&list[fd]);
	return (line);
}

/**
 * @details 
 *  - While there is no '\n' in the list I read another BUFFER_SIZE string
 *  and add it as content of a new node at the end of the list
*/
void	create_list(t_line **list, int fd)
{
	int		bytes_read;
	char	*buffer;

	while (!find_nl(*list))
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buffer);
			return ;
		}
		buffer[bytes_read] = 0;
		ft_lineadd_back(list, buffer);
	}
}

/**
 * @details
 * - We copy to str at most len (length till '\n) characters of the list
*/
char	*read_line(t_line *list)
{
	int		len;
	char	*str;

	if (!list)
		return (0);
	len = len_nl(list);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	gnl_strcopy(list, str);
	return (str);
}

/**
 * @details 
 *  - If any of the mallocs fail function has no effect
 *  - Read the content until '\0' or '\n' is found
 *  - Copy to the buffer until '\0' (if it was not found before)
 *  - Free the memory
*/
void	update_list(t_line **list)
{
	t_line	*last_node;
	t_line	*new_node;
	int		i;
	int		j;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	new_node = (t_line *)malloc(sizeof(t_line));
	if (buffer && new_node)
	{
		last_node = ft_linelast(*list);
		i = 0;
		j = 0;
		while (last_node->content[i] != 0 && last_node->content[i] != '\n')
			i++;
		while (last_node->content[i] != 0 && last_node->content[++i])
			buffer[j++] = last_node->content[i];
		buffer[j] = 0;
		new_node->content = buffer;
		new_node->next = 0;
		free_mem(list, new_node, buffer);
	}
}

/**
 * @details
 * - free the memory of the content of the nodes and the nodes
 * - if the node is not NULL the list points to it
 * - else we free the buffer and the node
*/
void	free_mem(t_line **list, t_line *node, char *buffer)
{
	t_line	*tmp;

	if (list)
	{
		while (*list)
		{
			tmp = (*list)->next;
			free((*list)->content);
			free(*list);
			*list = tmp;
		}
		*list = 0;
		if (node)
		{
			if (node->content && node->content[0])
				*list = node;
			else
			{
				if (buffer)
					free(buffer);
				free(node);
			}
		}
	}
}
