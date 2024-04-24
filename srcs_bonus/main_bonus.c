/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuarros <ejuarros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:26:12 by ejuarros          #+#    #+#             */
/*   Updated: 2024/04/24 10:17:22 by ejuarros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

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
	pipex.argc = argc - 1;
	pipex.argv = argv + 1;
	pipex.env = env;
	start_pipex(&pipex);
	return (0);
}
