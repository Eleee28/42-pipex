/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:11:02 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:06:37 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_putendl_fd.c 
 * 	@brief Working with file descriptors
 * 
 * 	This function sends a string to a file descriptor followed by an endline.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief sends a string to a file descriptor followed by an endline
 * 
 * 	@param s string to send
 * 	@param fd file descriptor 
 * 	@return Void
*/
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
