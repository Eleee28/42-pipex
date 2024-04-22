/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:59:35 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:07:14 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_strnstr.c 
 * 	@brief Libc strnstr function
 * 
 * 	This function locates the first occurrence of a string in another one.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief locates the first occurrence of a string in another one
 * 
 * 	Locates the first occurrence of the null-terminated string needle in the 
 * 	string haystack, where not more than len characters are searched.  
 * 
 * 	Characters that appear after a `\0' character are not searched.
 * 
 * 	@param haystack string where we search
 * 	@param needle searched string
 * 	@param len maximum length to search
 * 	@return haystack if needle is empty, NULL if it is not found in haystack,
 * 			otherwise pointer to the first occurrence
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j] && needle[j]
			&& i + j < len)
			j++;
		if (!needle[j])
			return ((char *)haystack + i);
		j = 0;
		i++;
	}
	return (0);
}
