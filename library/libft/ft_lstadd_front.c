/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 09:46:51 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:05:55 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_lstadd_front.c 
 * 	@brief Function to manipulate lists
 * 
 * 	This function adds a node at the beggining of the list.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief adds a node at the beggining of the list
 * 
 * 	If the list does not exist the function has no effect.
 * 
 * 	@param lst double pointer to the list
 * 	@param new node to add to the list
 * 	@return Void
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}
