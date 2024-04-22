/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:29:44 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:06:24 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_memcmp.c 
 * 	@brief Libc memcmp function
 * 
 * 	This function compares two byte strings.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief compares two byte strings
 * 
 * 	Both strings are assumed to be the same length.
 * 
 * 	@param s1 string 1
 * 	@param s2 string 2
 * 	@param n length of the strings
 * 	@return 0 if they are identical, otherwise the difference betwwen the first 
 * 			two differencing bytes
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && i < n - 1)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
