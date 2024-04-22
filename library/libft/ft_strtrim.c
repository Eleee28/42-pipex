/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:45:35 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:07:19 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_strtrim.c 
 * 	@brief Working with strings
 * 
 * 	This function deletes characters in a set from a string.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief locates a character in a string
 * 
 * 	@param s string
 * 	@param c character to locate
 * 	@return true if found, else false
*/
static int	find_char(char const *s, char c)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (*(s + i) && !found)
	{
		if (s[i] == c)
			found = 1;
		else
			i++;
	}
	return (found);
}

/** @brief deletes characters in a set from a string
 * 
 * 	Deletes all characters in set from the beggining to the end of s1, until
 * 	finding a character that does not beong to set.
 * 
 * 	@param s1 string
 * 	@param set string with characters to delete
 * 	@return new string with characters already deleted
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		end;
	int		beg;
	int		aux;

	beg = 0;
	while (s1[beg] && find_char(set, s1[beg]))
		beg++;
	end = ft_strlen(s1);
	while (beg < end && find_char(set, s1[end - 1]))
		end--;
	aux = end - beg + 1;
	str = malloc(aux);
	if (!str)
		return (0);
	if (aux <= 0)
		return (0);
	ft_strlcpy(str, &s1[beg], (end - beg + 1));
	return (str);
}
