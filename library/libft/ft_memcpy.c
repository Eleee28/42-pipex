/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:56:21 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:06:27 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_memcpy.c 
 * 	@brief Libc memcpy function
 * 
 * 	This function copies bytes from one memory area to another.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief copies bytes from one memory area to another
 * 
 * 	If dest and src overlap, behavior is undefined.
 * 
 * 	@param dest destination pointer
 * 	@param src source pointer
 * 	@param n number of bytes to copy 
 * 	@return pointer to the original value of dest
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*aux_src;
	unsigned char		*aux_dest;

	if (!src && !dest)
		return (0);
	aux_dest = dest;
	aux_src = src;
	while (n--)
		*aux_dest++ = *aux_src++;
	return (dest);
}
