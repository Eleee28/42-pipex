/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:09:07 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:06:43 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_putstr_fd.c 
 * 	@brief Working with file descriptors
 * 
 * 	This function sends a string to a file descriptor.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief sends a string to a file descriptor
 * 
 * 	@param s string to send
 * 	@param fd file descriptor 
 * 	@return Void
*/
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
