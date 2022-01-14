/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:27:27 by cbeaurai          #+#    #+#             */
/*   Updated: 2021/09/27 16:10:14 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib_pipex.h"
#include "./global/libft.h"

int	main(int ac, char **av, char **envp)
{
	t_vars	*vars;

	if (ac != 5)
		ft_wrong_arg();
	vars = ft_setup_args(av, envp);
	ft_pipex(vars, envp);
	return (0);
}
