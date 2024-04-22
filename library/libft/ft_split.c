/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:02:52 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/29 08:13:53 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_split.c 
 * 	@brief Separate two strings
 * 
 * 	This function splits two strings using a character as delimiter.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief counts the number of words using a character as separator
 * 
 * 	@param s string to split
 * 	@param c character that acts as separator
 * 	@return number of words
*/
static int	count_words(char const *s, char c)
{
	char	last;
	int		i;
	int		cnt;

	last = c;
	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (last == c && s[i] != c)
			cnt++;
		last = s[i];
		i++;
	}
	return (cnt);
}

/** @brief gets the length of a string using a character as end of string
 * 
 * 	@param s string to check length
 * 	@param c character that acts as end
 * 	@return length
*/
static int	substr_len(char const *s, char c, int len)
{
	int	n;

	n = 0;
	while (s[len])
	{
		if (s[len] == c)
			return (n);
		len++;
		n++;
	}
	return (n);
}

/** @brief fills a string with info of another
 * 
 * 	@param s string with the info
 * 	@param str string to fill
 * 	@param pos index of s to start copying
 * 	@param len maximum length to copy
 * 	@return length of str
*/
static int	fill(const char *s, char *str, int pos, int len)
{
	int	j;

	j = 0;
	while (j < len)
	{
		str[j] = s[pos];
		j++;
		pos++;
	}
	str[j] = 0;
	return (j);
}

/** @brief frees the dynamic memory 
 * 
 * 	@param str double pointer to characters
 * 	@param len length of the string
 * 	@return 0
*/
static char	**free_split(char **str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

/** @brief splits two strings using a character as delimiter 
 * 
 * 	If malloc fails, the function has no effect.
 * 
 * 	@param s string to be split
 * 	@param c character that acts as delimiter
 * 	@return 2d array with the split string
*/
char	**ft_split(char const *s, char c)
{
	char			**str;
	int				i;
	int				j;
	int				len_substr;

	str = (char **)malloc(sizeof(*str) * (count_words(s, c) + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		len_substr = substr_len(s, c, i);
		str[j] = (char *)malloc(sizeof(char) * (len_substr + 1));
		if (!str[j])
			return (free_split(str, j));
		i += fill(s, str[j], i, len_substr);
		j++;
	}
	str[j] = 0;
	return (str);
}
