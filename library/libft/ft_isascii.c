/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:55:22 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:05:40 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_isascii.c
 * 	@brief Libc isascii function
 * 
 * 	This function tests whether a character is ASCII.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief tests whether a character is ASCII
 * 
 * 	An ASCII character is any character between 0 and 127 inclusive
 * 
 * 	@param c character to test
 * 	@return 0 if the character tests false, 1 if the character tests true
*/
int	ft_isascii(int c)
{
	int	ret_value;

	if ((c >= 0) && (c <= 127))
		ret_value = 1;
	else
		ret_value = 0;
	return (ret_value);
}
