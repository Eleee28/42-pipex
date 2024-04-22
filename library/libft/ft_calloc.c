/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:10:34 by codespace         #+#    #+#             */
/*   Updated: 2024/02/01 08:05:29 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_calloc.c
 * 	@brief Libc calloc function
 * 
 * 	This function allocates memory.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief allocates memory
 * 
 * 	This function contiguosly allocates enough space. The allocated memory is 
 * 	filled with zeroed bytes.
 * 
 * 	@param nmemb number of objects the memory is allocated for
 * 	@param size bytes of memory of each object
 * 	@return pointer to the allocated memory
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
