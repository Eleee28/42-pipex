/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:57:28 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:06:32 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_memset.c 
 * 	@brief Libc memset function
 * 
 * 	This function writes a number of characters to a string.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief writes a number of characters to a string
 * 
 * 	The character is converted to an unsigned char.
 * 
 * 	@param s pointer to string
 * 	@param c character to write
 * 	@param n number of bytes to write
 * 	@return pointer to string
*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*aux;

	aux = s;
	while (n > 0)
	{
		*aux = (unsigned char)c;
		aux++;
		n--;
	}
	return (s);
}
