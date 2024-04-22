/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:56:06 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:06:22 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_memchr.c 
 * 	@brief Libc memchr function
 * 
 * 	This function locates the first occurrence of a character in a string.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief locates the first occurrence of a character in a string
 * 
 * 	The character is converted to an unsigned char.
 * 
 * 	@param s string
 * 	@param c character to locate
 * 	@param n number of bytes of s to search 
 * 	@return pointer to the first occurrence
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (0);
}
