/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:59:32 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:07:12 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_strncmp.c 
 * 	@brief Libc strncmp function
 * 
 * 	This function lexicographically compares two null-terminated strings.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief lexicographically compares two null-terminated strings
 * 
 * 	It compares not more than n characters. It is designed for comparing strings 
 * 	rather than binary data. Characters that appear after a `\0' character 
 * 	are not compared.
 * 
 * 	@param s1 string 1
 * 	@param s2 string 2
 * 	@param n maximum length to compare
 * 	@return 0 if they are identical, otherwise the difference betwwen the first 
 * 			two differencing bytes
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		ret_value;
	size_t	i;

	i = 0;
	ret_value = 0;
	while (s1[i] && s2[i] && ret_value == 0 && i < n)
	{
		ret_value = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (ret_value == 0 && i < n)
		ret_value = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (ret_value);
}
