/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:46:49 by ejuarros          #+#    #+#             */
/*   Updated: 2024/01/24 08:25:19 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/** @brief Printf function from stdio.h
*
*  @details After a '%' we read flags and argument types, else we print.
*  va_list is used to accept a variable number of arguments
*  va_start is used for "starting the list" (initiates the list to point 
*  	to the first variable argument)
*  va_arg is used to get the next argument from the list
*  va_end is used for "ending the list", it cleans things up
*
*  @param str string with text, flags and type identifiers
*  @param ... unkown number of parameters to print
*
*  @return length of the printed output
*/
int	ft_printf(char const *str, ...)
{
	va_list	args;
	t_flags	flags;
	int		len;
	int		i;

	if (!str)
		return (-1);
	va_start(args, str);
	len = 0;
	i = 0;
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			i += ft_flags(&flags, &str[i]);
			ft_putargs(&len, &flags, args);
		}
		else
			ft_printchar(&len, str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
