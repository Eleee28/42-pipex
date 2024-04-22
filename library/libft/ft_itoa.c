/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:31:39 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/28 11:31:34 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_itoa.c 
 * 	@brief itoa function (oposite to libc atoi function)
 * 
 * 	This function converts an integer to a string.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief counts the digits of number
 * 
 * 	If the number is 0, that is one digit. If the number is negative, the 
 * 	sign counts as an extra digit.
 * 
 * 	@param n number to count its digits
 * 	@return number of digits
*/
static int	count_digits(int n)
{
	int	digits;
	int	aux;

	digits = 0;
	aux = n;
	if (n == 0)
		digits++;
	while (aux != 0)
	{
		digits++;
		aux /= 10;
	}
	if (n < 0)
		digits++;
	return (digits);
}

/** @brief permorms absolute value operation 
 * 
 * 	@param n number to operate
 * 	@return absolute value
*/
static int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

/** @brief converts an integer to a string
 * 
 *	Use of malloc to allocate memory for the string. If malloc fails the
 *  function has no effect.
 * 
 * 	@param n number to be converted
 * 	@return string
*/
char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		len;

	len = count_digits(n);
	str = malloc(len + 1);
	if (!str)
		return (0);
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
	}
	if (n == 0)
		str[0] = '0';
	str[len] = 0;
	len--;
	while (len >= i)
	{
		str[len] = (char){(ft_abs(n % 10)) + '0'};
		n /= 10;
		len--;
	}
	return (str);
}
