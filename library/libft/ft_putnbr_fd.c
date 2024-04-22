/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:10:04 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:06:41 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_putnbr_fd.c 
 * 	@brief Working with file descriptors
 * 
 * 	This function sends a number to a file descriptor.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief sends a number to a file descriptor
 * 
 * 	@param n number to send
 * 	@param fd file descriptor 
 * 	@return Void
*/
void	ft_putnbr_fd(int n, int fd)
{
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10, fd);
	else if (n < 0)
		ft_putchar_fd('-', fd);
	if (n < 0)
		ft_putchar_fd((char){'0' - (n % 10)}, fd);
	if (n >= 0)
		ft_putchar_fd((char){'0' + (n % 10)}, fd);
}
