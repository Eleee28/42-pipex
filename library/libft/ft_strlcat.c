/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:59:07 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:07:02 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_strlcat.c 
 * 	@brief Libc strlcat function
 * 
 * 	This function copies and concatenate a string to another.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief measures the total length of the concatenation
 * 
 * 	@param src source string
 *	@param dest destination string
 *	@param size number of characters to concatenate
 * 	@return length of the resulting string
*/
static int	ft_total_len(const char *src, const char *dest, size_t size)
{
	size_t	src_len;
	size_t	dest_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	dest_len = 0;
	while (dest[dest_len] && dest_len < size)
		dest_len++;
	return (dest_len + src_len);
}

/** @brief copies and concatenate a string to another
 * 
 *  Take the full size of the destination buffer and guarantee NULL-termination 
 * 	if there is room.  Room for the NULL should be included in size.
 * 
 * 	Appends string src to the end of dest.  It will append at most 
 * 	size - strlen(dest) - 1 characters.  It will then NULL-terminate, unless 
 * 	size is 0 or the original dest string was longer than size.
 * 
 * 	If the src and dst strings overlap, the behavior is undefined.
 * 
 * 	@param dest destination string
 *	@param src source string
 *	@param size number of characters to concatenate
 * 	@return length of dest + length of src
*/
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	total_len;

	total_len = ft_total_len(src, dest, size);
	i = 0;
	j = 0;
	while (dest[i])
		i++;
	if (i < size)
	{
		while (src[j] && i < size - 1)
		{
			dest[i] = src[j];
			i++;
			j++;
		}
	}
	dest[i] = '\0';
	return (total_len);
}
