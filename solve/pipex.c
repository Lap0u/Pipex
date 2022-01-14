/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:12:23 by cbeaurai          #+#    #+#             */
/*   Updated: 2021/09/28 12:29:21 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_pipex.h"
#include  "../global/libft.h"

void	ft_pipex(t_vars *vars, char **envp)
{
	int		end[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	pipe(end);
	child1 = fork();
	if (child1 < 0)
		return (perror("Fork : "));
	if (child1 == 0)
		ft_1process(vars, end, envp);
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork : "));
	if (child2 == 0)
		ft_2process(vars, end, envp);
	close(end[0]);
	close(end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
	ft_exit_success(vars);
}
