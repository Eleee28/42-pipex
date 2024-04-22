/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:59:39 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:07:17 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_strrchr.c 
 * 	@brief Libc strrchr function
 * 
 * 	This function locates the last occurrence of a character in a string.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief locates the last occurrence of a character in a string
 * 
 * 	The character is converted to an unsigned char. The terminating null
 *  character is considered to be part of the string.
 * 
 * 	@param s string
 * 	@param c character to locate
 * 	@return pointer to the last occurrence, NULL if not found
*/
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (ptr[i])
		i++;
	while (i >= 0)
	{
		if (ptr[i] == (char)c)
			return ((char *)&ptr[i]);
		i--;
	}
	return (0);
}
