/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:29:57 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:05:58 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_lstclear.c 
 * 	@brief Function to manipulate lists
 * 
 * 	This function deletes and frees a node and all the consecutive ones.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief deletes and frees a node and all the consecutive ones
 * 
 * 	If the list does not exist the function has no effect. At the end, the 
 * 	pointer to the list must be NULL.
 * 
 * 	@param lst double pointer to the list
 * 	@param new pointer to a delete function
 * 	@return Void
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	while (*lst)
	{
		aux = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(aux, del);
	}
}
