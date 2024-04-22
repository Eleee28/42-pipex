/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:59:42 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:07:25 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_tolower.c
 * 	@brief Upper case to lower case conversion
 * 
 * 	This function converts from upper case to lower case.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief converts a letter from upper case to lower case
 * 
 * 	@param c character to convert
 * 	@return the lower case letter if c is an upper case letter, c otherwise
*/
int	ft_tolower(int c)
{
	if ((c >= 'A' && c <= 'Z'))
		c += 32;
	return (c);
}
