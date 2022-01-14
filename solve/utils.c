/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:21:43 by cbeaurai          #+#    #+#             */
/*   Updated: 2021/09/28 12:33:11 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global/libft.h"
#include "../lib_pipex.h"

void	ft_1process(t_vars *vars, int end[2], char **envp)
{
	int	ret;

	close(end[0]);
	ret = dup2(vars->fd1, STDIN_FILENO);
	if (ret < 0)
		ft_dup2_fail(vars);
	close(vars->fd1);
	ret = dup2(end[1], STDOUT_FILENO);
	if (ret < 0)
		ft_dup2_fail(vars);
	execve(vars->arg1[0], vars->arg1, envp);
	perror("ERROR ");
	free(vars);
}

void	ft_2process(t_vars *vars, int end[2], char **envp)
{
	int	ret;

	close(end[1]);
	ret = dup2(end[0], STDIN_FILENO);
	if (ret < 0)
		ft_dup2_fail(vars);
	close(end[0]);
	ret = dup2(vars->fd2, STDOUT_FILENO);
	if (ret < 0)
		ft_dup2_fail(vars);
	close(vars->fd2);
	execve(vars->arg2[0], vars->arg2, envp);
	perror("Error : ");
	free(vars);
}
