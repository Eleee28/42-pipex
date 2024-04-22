/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:58:58 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:06:49 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_strchr.c 
 * 	@brief Libc strchr function
 * 
 * 	This function locates the first occurrence of a character in the string.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief locates the first occurrence of a character in the string
 * 
 * 	The terminating null character is considered to be part of the string.
 * 
 * 	@param str string where the search is done
 *	@param c character searched
 * 	@return pointer to the first occurrence of the character, 
 *			NULL if not found
*/
char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (!*str)
			return (0);
		else
			str++;
	}
	return ((char *)str);
}
