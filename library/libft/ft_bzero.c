/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:54:26 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:05:26 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_bzero.c
 * 	@brief Libc bzero function
 * 
 * 	This function writes zeroes to a byte string.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief writes zeroes to a byte string
 * 
 * 	Writes n zeroed bytes to the string s. If n is zero, the function has no
 * 	effect.
 * 
 * 	@param s string where zeroes are written
 * 	@param n number of zeroed bytes written
 * 	@return Void 
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
