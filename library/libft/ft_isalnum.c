/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:54:46 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:05:33 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_isalnum.c
 * 	@brief Libc isalnum function
 * 
 * 	This function tests whether a character is alphanumeric.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief tests whether a character is alphanumeric
 * 
 * 	This function makes calls to ft_isalpha() and ft_isdigit().
 * 
 * 	The value of the argument must be representable as an unsigned char or the 
 * 	value of EOF.
 * 
 * 	@param c character to test
 * 	@return 0 if the character tests false, 1 if the character tests true
*/
int	ft_isalnum(int c)
{
	int	ret_value;

	if (ft_isalpha(c) || ft_isdigit(c))
		ret_value = 1;
	else
		ret_value = 0;
	return (ret_value);
}
