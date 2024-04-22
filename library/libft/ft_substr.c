/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 06:31:28 by codespace         #+#    #+#             */
/*   Updated: 2024/02/01 08:07:22 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_substr.c 
 * 	@brief Working with strings
 * 
 * 	This function returns a substring.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief returns a substring
 * 
 * 	The substring starts with index start and has a maximun length of len.
 * 
 * 	@param s string
 * 	@param start beggining index
 * 	@param len maximum len of the substring
 * 	@return pointer to the substring
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
