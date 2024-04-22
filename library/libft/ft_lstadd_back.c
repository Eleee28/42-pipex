/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:33:19 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:05:52 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_lstadd_back.c 
 * 	@brief Function to manipulate lists
 * 
 * 	This function adds a node at the end of the list.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief adds a node at the end of the list
 * 
 * 	If the list does not exist the function has no effect.
 * 
 * 	@param lst double pointer to the list
 * 	@param new node to add to the list
 * 	@return Void
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
