/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:10:29 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:06:01 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_lstdelone.c 
 * 	@brief Function to manipulate lists
 * 
 * 	This function frees the memory of the content and its node.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief frees the memory of the content and its node
 * 
 * 	The memory of 'next' must not be freed.
 * 
 * 	@param lst double pointer to the list
 * 	@param new pointer to a delete function
 * 	@return Void
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
