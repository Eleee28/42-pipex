/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 09:54:08 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:05:19 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_atoi.c
 * 	@brief Libc atoi function
 * 
 * 	This function converts a string into an integer.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief converts a string into an integer
 * 
 * 	If the ' ', '\t', '\n', '\v', '\r', '\f' are encountered at the 
 *  beggining of the string they would be skipped. The sign should be 
 *  handled. If any non numeric character is encountered it stops reading
 *  and returns the number up to that point. 
 * 
 * 	@param nptr string to be converted
 * 	@return integer number
*/
int	ft_atoi(const char *nptr)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\r' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (num * sign);
}
