/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:48:06 by ejuarros          #+#    #+#             */
/*   Updated: 2024/01/23 10:55:35 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/** @brief Prints a character
 * 
 *  @details It also increments len
 * 
 *  @param len length of the printed output
 *  @param c character to print
 * 
 *  @return void
*/
void	ft_printchar(int *len, char c)
{
	write(1, &c, 1);
	(*len)++;
}

/** @brief Prints a character applying flags
 * 
 *  @details If flag '-' is not present print as many ' ' as the width.
 *  Then, print the character and after that, if the flag '-' is present, 
 *  print as many ' ' as the width.
 * 
 *  @param flags structure that stores flags information
 *  @param len length of the printed output
 *  @param c character to print
 *  
 *  @return void
*/
void	ft_putchar(t_flags *flags, int *len, char c)
{
	int	i;

	i = 0;
	while (flags->justified != '-' && i + 1 < flags->width)
	{
		ft_printchar(len, ' ');
		i++;
	}
	ft_printchar(len, c);
	i = 0;
	while (flags->justified == '-' && i + 1 < flags->width)
	{
		ft_printchar(len, ' ');
		i++;
	}
}
