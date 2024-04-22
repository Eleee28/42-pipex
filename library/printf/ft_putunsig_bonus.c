/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsig_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:50:53 by ejuarros          #+#    #+#             */
/*   Updated: 2024/01/24 08:42:39 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/** @brief Convert an unsigned number to string
 * 
 *  @details Add zeroes at the beggining 
 *  to match the length.
 * 
 *  @param n number to convert
 *  @param len length of the string
 *  @param str string where the converted number is stored
 * 
 *  @return void
*/
static void	ft_unsig_to_str(unsigned int n, int len, char *str)
{
	int	i;

	str[len] = 0;
	i = 1;
	while (n != 0)
	{
		str[len - i] = "0123456789"[n % 10];
		n /= 10;
		i++;
	}
	while (i <= len)
	{
		str[len - i] = '0';
		i++;
	}
}

/** @brief Print unsigned number
 * 
 *  @param flags structure that stores flags information
 *  @param n number to print
 * 
 *  @return string to print taking into account the flags
*/
char	*ft_putunsig(t_flags *flags, unsigned int n)
{
	int		len;
	char	*str;

	len = ft_unsiglen(n, 10);
	if (!flags->precision && !n)
		len = 0;
	else if (flags->precision >= len)
		len = flags->precision;
	if (flags->precision < 0 && flags->justified == '0' && flags->width >= len)
		len = flags->width;
	str = (char *)malloc((len + 1) * sizeof(char));
	ft_unsig_to_str(n, len, str);
	return (str);
}
