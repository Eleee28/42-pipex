/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:02:15 by ele               #+#    #+#             */
/*   Updated: 2024/04/22 12:05:51 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_utils.h"
#include "../libft/libft.h"

char	**ft_dup_matrix(char **src)
{
	char	**dup;
	int		i;

	dup = (char **)malloc((ft_len_matrix(src) + 1) * sizeof(char *));
	if (!dup)
		return (0);
	i = 0;
	while (src && src[i])
	{
		dup[i] = ft_strdup(src[i]);
		i++;
	}
	dup[i] = 0;
	return (dup);
}
