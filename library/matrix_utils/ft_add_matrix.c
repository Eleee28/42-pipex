/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:30:30 by ejuarros          #+#    #+#             */
/*   Updated: 2024/03/06 08:17:49 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_utils.h"

/** @brief adds a string at the end of an array of strings
 * 
 *  @param str array of strings
 *  @param s string to add
 * 
 *  @return new string with s added to str
*/
char	**ft_add_matrix(char **str, char *s)
{
	char	**new;
	int		i;

	new = (char **)malloc(sizeof(char *) * (ft_len_matrix(str) + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = s;
	new[++i] = NULL;
	free(str);
	return (new);
}
