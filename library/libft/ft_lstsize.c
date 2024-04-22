/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:07:44 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:06:20 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_lstsize.c 
 * 	@brief Function to manipulate lists
 * 
 * 	This function counts the number of nodes of a list.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief counts the number of nodes of a list
 * 
 * 	@param lst pointer to the list
 * 	@return number of nodes of the list
*/
int	ft_lstsize(t_list *lst)
{
	int		len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
