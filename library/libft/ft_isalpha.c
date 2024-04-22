/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:55:03 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:05:37 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_isalpha.c
 * 	@brief Libc isalpha function
 * 
 * 	This function tests whether a character is alphabetical.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief tests whether a character is lower-case
 * 
 * 	The value of the argument must be representable as an unsigned char or the 
 * 	value of EOF.
 * 
 * 	@param c character to test
 * 	@return 0 if the character tests false, 1 if the character tests true
*/
static int	ft_islower(int c)
{
	int	ret_value;

	if (c >= 'a' && c <= 'z')
		ret_value = 1;
	else
		ret_value = 0;
	return (ret_value);
}

/** @brief tests whether a character is upper-case
 * 
 * 	The value of the argument must be representable as an unsigned char or the 
 * 	value of EOF.
 * 
 * 	@param c character to test
 * 	@return 0 if the character tests false, 1 if the character tests true
*/
static int	ft_isupper(int c)
{
	int	ret_value;

	if (c >= 'A' && c <= 'Z')
		ret_value = 1;
	else
		ret_value = 0;
	return (ret_value);
}

/** @brief tests whether a character is alphabetical
 * 
 * 	This function makes calls to ft_islower() and ft_isupper().
 * 
 * 	The value of the argument must be representable as an unsigned char or the 
 * 	value of EOF.
 * 
 * 	@param c character to test
 * 	@return 0 if the character tests false, 1 if the character tests true
*/
int	ft_isalpha(int c)
{
	int	ret_value;

	if (ft_islower(c) || ft_isupper(c))
		ret_value = 1;
	else
		ret_value = 0;
	return (ret_value);
}
