/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:38:38 by ejuarros          #+#    #+#             */
/*   Updated: 2024/07/10 13:44:10 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/** @details search for "PATH=" in the env variables and split the result
 *  using ':' as delimiter.
*/
char	*get_path(char **env, char *arg)
{
	int		i;
	char	**path;

	path = 0;
	i = 0;
	while (env && env[i] && !path)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path = ft_split(env[i] + 5, ':');
		i++;
	}
	return (find_path(path, arg));
}

/** @details find the first path that can be accessed with the arg in the path
 */
char	*find_path(char **path, char *arg)
{
	char	*aux1;
	char	*aux2;
	int		i;

	i = 0;
	while (path && path[i])
	{
		aux1 = ft_strjoin(path[i], "/");
		aux2 = ft_strjoin(aux1, arg);
		free(aux1);
		if (access(aux2, F_OK) == 0)
		{
			ft_free_matrix(path);
			return (aux2);
		}
		free(aux2);
		i++;
	}
	if (path)
		arg = 0;
	ft_free_matrix(path);
	return (arg);
}

/** @details call perror to print the error message stored in errno along with
 * 	msg. Exit the program.
*/
void	perror_msg(char *msg)
{
	perror(msg);
	exit(1);
}
