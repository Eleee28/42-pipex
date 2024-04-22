/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:30:49 by ejuarros          #+#    #+#             */
/*   Updated: 2024/04/22 12:07:08 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// add to lib strcmp
#ifndef MATRIX_UTILS_H
# define MATRIX_UTILS_H

# include <stdlib.h>

void	ft_free_matrix(char **str);
size_t	ft_len_matrix(char **str);
char	**ft_add_matrix(char **str, char *s);
void	ft_print_matrix(char **matrix);
void	ft_copy_matrix(char **src, char **dest);
char	**ft_dup_matrix(char **src);

#endif