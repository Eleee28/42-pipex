/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:49:55 by ejuarros          #+#    #+#             */
/*   Updated: 2024/01/23 10:55:42 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/** @brief Convert a pointer (int) to string
 * 
 *  @details Similar idea to itoa. If there is a sign store it, if not 
 *  just 0x.
 * 
 *  @param ptr pointer to convert
 *  @param len length of the string
 *  @param sign sign flag
 *  @param str string where the converted pointer is stored
 * 
 *  @return void
*/
static void	ft_ptr_to_str(unsigned long int ptr, int len, char sign, char *str)
{
	int	i;

	str[len] = 0;
	i = 1;
	while (ptr != 0)
	{
		str[len - i] = "0123456789abcdef"[ptr % 16];
		ptr /= 16;
		i++;
	}
	if (sign)
	{
		str[0] = sign;
		str[1] = '0';
		str[2] = 'x';
	}
	else
	{
		str[0] = '0';
		str[1] = 'x';
	}
}

/** @brief Print a pointer
 * 
 *  @details If ptr is not NULL, its length is strlen(ptr) + 2 (0x) 
 *  + 1 (if there is a sign). Allocate memory (len chars).
 * 
 *  @param flags structure that stores flags information
 *  @param ptr pointer to print
 * 
 *  @return string to print taking into account the flags
*/
char	*ft_putptr(t_flags *flags, unsigned long int ptr)
{
	int		len;
	char	*str;

	if (!ptr)
		str = ft_putstr(-1, "0x0");
	else
	{
		len = ft_unsiglen(ptr, 16) + 2;
		if (flags->sign)
			len++;
		str = (char *)malloc((len + 1) * sizeof(char));
		ft_ptr_to_str(ptr, len, flags->sign, str);
	}
	return (str);
}
