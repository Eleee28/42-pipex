/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:49:29 by ejuarros          #+#    #+#             */
/*   Updated: 2024/01/24 08:42:10 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/** @brief Convert an hexadecimal number to string
 * 
 *  @details Add zeroes at the beggining to match the length. Add '0x' if 
 *  the flags require so.
 * 
 *  @param ptr pointer to convert
 *  @param len length of the string
 *  @param sign sign flag
 *  @param str string where the converted pointer is stored
 * 
 *  @return void
*/
static void	ft_hex_to_str(unsigned int n, int len, char sign, char *str)
{
	int	i;

	str[len] = 0;
	i = 1;
	while (n != 0)
	{
		str[len - i] = "0123456789abcdef"[n % 16];
		n /= 16;
		i++;
	}
	while (i <= len)
	{
		str[len - i] = '0';
		i++;
	}
	if (sign && len)
	{
		str[0] = '0';
		str[1] = 'x';
	}
}

/** @brief Print hexadecimal number in lower case
 * 
 *  @param flags structure that stores flags information
 *  @param n number to print
 * 
 *  @return string to print taking into account the flags
*/
char	*ft_puthex_low(t_flags *flags, unsigned int n)
{
	int		len;
	char	*str;

	len = ft_unsiglen(n, 16);
	if (!n)
		flags->hex = 0;
	if (flags->precision >= len)
		len = flags->precision;
	else if (flags->precision < 0 && flags->justified == '0')
	{
		if (flags->hex && flags->width - 2 >= len)
			len = flags->width - 2;
		if (!flags->hex && flags->width >= len)
			len = flags->width;
	}
	if (flags->hex == '#')
		len += 2;
	if (!flags->precision && !n)
		len = 0;
	str = (char *)malloc((len + 1) * sizeof(char));
	ft_hex_to_str(n, len, flags->hex, str);
	return (str);
}

/** @brief Print hexadecimal number in upper case
 * 
 *  @param flags structure that stores flags information
 *  @param n number to print
 * 
 *  @return string to print taking into account the flags
 * 
*/
char	*ft_puthex_up(t_flags *flags, unsigned int n)
{
	char	*str;
	int		i;

	str = ft_puthex_low(flags, n);
	i = 0;
	while (str && str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
