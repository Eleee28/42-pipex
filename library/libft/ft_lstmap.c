/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:52:07 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:06:15 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_lstmap.c 
 * 	@brief Function to manipulate lists
 * 
 * 	This function creates a list result of applying a function to each node 
 * 	of the original list.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief creates a list result of applying a function to each node of the 
 * 	original list
 * 
 * 	Iterates the list and applies the function to the content of each node. 
 * 	Creates a resulting list of the correct and succesive way of applying the
 * 	function on each node. 
 * 
 * 	If malloc fails the function has no effect. If any of the parameters is 
 * 	NULL the function has no effect.
 * 
 * 	@param lst pointer to the list
 * 	@param f pointer to a function
 * 	@param del pointer to a delete function
 * 	@return pointer to a list
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*aux1;
	void	*cont;

	if (!lst || !f || !del)
		return (0);
	new = 0;
	while (lst)
	{
		cont = f(lst->content);
		aux1 = ft_lstnew(cont);
		if (!aux1)
		{
			del(cont);
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, aux1);
		lst = lst->next;
	}
	return (new);
}
