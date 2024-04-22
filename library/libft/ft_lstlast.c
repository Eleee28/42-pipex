/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:23:40 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:06:12 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_lstlast.c 
 * 	@brief Function to manipulate lists
 * 
 * 	This function returns the last node of the list.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief returns the last node of the list
 * 
 * 	If the list does not exist the function has no effect.
 * 
 * 	@param lst pointer to the list
 * 	@return last node of the list
*/
t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
