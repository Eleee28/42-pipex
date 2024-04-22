/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:45:41 by ejuarros          #+#    #+#             */
/*   Updated: 2024/01/23 11:45:08 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/** @brief Converts a string into an integer.
 * 
 * 	@details If the ' ', '\t', '\n', '\v', '\r', '\f' are encountered at 
 *  the beggining of the string they would be skipped. The sign should be 
 *  handled. If any non numeric character is encountered it stops reading 
 *  and returns the number up to that point. 
 * 
 * 	@param nptr string to be converted
 * 	@return integer number
*/
static int	ft_atoi(const char *nptr)
{
	int	sign;
	int	num;
	int	i;

	sign = 1;
	num = 0;
	i = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	return (sign * num);
}

/** @brief Consider flags width and precision.
 * 
 *  @details Using the atoi function store the width (skip the 
 *  characters  after). If a '.' is found store precision as 
 *  well (-1 by default). At last store the argument 
 *  (s, p, u, i, d, ...).
 * 
 *  @param flags structure that stores flags information
 *  @param str string to extract information from
 * 
 * 	@return number of characters read of str
*/
static int	ft_wid_pre(t_flags *flags, char const *str)
{
	int	i;

	i = 0;
	flags->width = ft_atoi(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		i++;
		flags->precision = ft_atoi(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	else
		flags->precision = -1;
	flags->arg = str[i];
	return (i);
}

/** @brief Get flags information
 * 
 * @details Set default values (i = 1 to skip '%').
 * If a flag is encountered treat it and store it considering the priority.
 * 
 *  @param flags structure that stores flags information
 * 	@param str string to extract information from
 * 
 *  @return number of characters read of str
*/
int	ft_flags(t_flags *flags, char const *str)
{
	int	i;

	flags->justified = 0;
	flags->sign = 0;
	flags->hex = 0;
	i = 1;
	while (str[i] == '-' || str[i] == '0' || str[i] == '+'
		|| str[i] == '#' || str[i] == ' ')
	{
		if (str[i] == '-')
			flags->justified = '-';
		else if (str[i] == '0' && flags->justified != '-')
			flags->justified = '0';
		else if (str[i] == '+')
			flags->sign = '+';
		else if (str[i] == ' ' && flags->sign != '+')
			flags->sign = ' ';
		else if (str[i] == '#')
			flags->hex = '#';
		i++;
	}
	i += ft_wid_pre(flags, &str[i]);
	return (i);
}
