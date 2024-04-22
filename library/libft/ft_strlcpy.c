/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:59:19 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:07:04 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_strlcpy.c 
 * 	@brief Libc strlcat function
 * 
 * 	This function copies and concatenate a string to another.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief copies and concatenate a string to another
 * 
 *  Take the full size of the destination buffer and guarantee NULL-termination 
 * 	if there is room.  Room for the NULL should be included in size.
 * 
 * 	Copies up to size - 1 characters from the string src to dest, 
 * 	NULL-terminating the result if size is not 0.
 * 
 * 	If the src and dest strings overlap, the behavior is undefined.
 * 
 * 	@param dest destination string
 *	@param src source string
 *	@param size number of characters to concatenate
 * 	@return length of src
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	size_src;
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	size_src = ft_strlen(src);
	return (size_src);
}
