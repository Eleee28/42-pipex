/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:10:40 by codespace         #+#    #+#             */
/*   Updated: 2024/02/01 08:06:52 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_strdup.c
 * 	@brief Libc strdup function
 * 
 * 	This function duplicates a string.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief duplicates a string
 * 
 * 	Allocates sufficient memory for a copy of the string and does the copy. 
 * 
 * 	If insufficient memory is available the function has no effect.
 * 
 * 	@param src string
 * 	@return pointer to the duplicate of the string, 
 *			NULL if there was any error
*/
char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*ptr;

	len = ft_strlen(src);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (i < len)
	{
		*(ptr + i) = *(src + i);
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
