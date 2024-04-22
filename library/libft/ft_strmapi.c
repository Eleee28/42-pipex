/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:45:09 by codespace         #+#    #+#             */
/*   Updated: 2024/02/01 08:07:09 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_strmapi.c 
 * 	@brief Apply functions to strings
 * 
 * 	This function applies a given function to each character of a string.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief applies a given function to each character of a string
 * 
 *  Genartes a new string that is the result of apppling the function.
 * 
 * 	@param s string
 *	@param f pointer to a function
 * 	@return new string
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
