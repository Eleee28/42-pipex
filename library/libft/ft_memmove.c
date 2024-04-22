/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:56:42 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:06:29 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_memmove.c 
 * 	@brief Libc memmove function
 * 
 * 	This function copies bytes from one string to another.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief copies bytes from one string to another
 * 
 * 	The two strings may overlap; the copy is always done in a non-destructive
 * 	manner.
 * 
 * 	@param dest destination pointer
 * 	@param src source pointer
 * 	@param n number of bytes to copy 
 * 	@return pointer to the original value of dest
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*aux_src;
	char		*aux_dest;

	aux_src = src;
	aux_dest = dest;
	if ((!dest && !src) || n <= 0)
		return (dest);
	if (aux_src < aux_dest && aux_src + n > aux_dest)
	{
		aux_dest += (n - 1);
		aux_src += (n - 1);
		while (n--)
			*aux_dest-- = *aux_src--;
	}
	else
		while (n--)
			*aux_dest++ = *aux_src++;
	return (dest);
}
