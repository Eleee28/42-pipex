/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 09:35:23 by ejuarros          #+#    #+#             */
/*   Updated: 2024/02/01 08:06:17 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ft_lstnew.c 
 * 	@brief Function to manipulate lists
 * 
 * 	This function creates a new node.
*/

/* -- Includes -- */
#include "libft.h"

/** @brief creates a new node
 * 
 * 	The content of the node is initialized with content and next with NULL.
 * 
 * 	@param content pointer to the content
 * 	@return new node
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->next = 0;
	new->content = content;
	return (new);
}
