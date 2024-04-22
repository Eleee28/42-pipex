/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:55:37 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:05:42 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_isdigit.c
 * 	@brief Libc isdigit function
 * 
 * 	This function tests whether a character is a decimal digit.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief tests whether a character is numeric
 * 
 * 	The value of the argument must be representable as an unsigned char or the 
 * 	value of EOF. 
 * 
 * Decimal digit characers are: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
 * 
 * 	@param c character to test
 * 	@return 0 if the character tests false, 1 if the character tests true
*/
int	ft_isdigit(int c)
{
	int	ret_value;

	if (c >= '0' && c <= '9')
		ret_value = 1;
	else
		ret_value = 0;
	return (ret_value);
}
