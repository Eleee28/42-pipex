/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:59:45 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:07:27 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_toupper.c
 * 	@brief Lower case to upper case conversion
 * 
 * 	This function converts from lower case to upper case.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief converts a letter from lower case to upper case
 * 
 * 	@param c character to convert
 * 	@return the uppper case letter if c is a lower case letter, c otherwise
*/
int	ft_toupper(int c)
{
	if ((c >= 'a' && c <= 'z'))
		c -= 32;
	return (c);
}
