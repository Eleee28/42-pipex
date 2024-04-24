/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:26:12 by ejuarros          #+#    #+#             */
/*   Updated: 2024/04/24 11:46:59 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	if (argc < 5)
	{
		ft_printf("Error: Wrong number of arguments\n");
		return (1);
	}
	else if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0 
		&& argc < 6)
	{
		ft_printf("Error: Wrong number of arguments\n");
		return (1);
	}
	start_pipex(argc - 1, argv + 1, env);
	return (0);
}
