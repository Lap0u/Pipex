/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:55:37 by cbeaurai          #+#    #+#             */
/*   Updated: 2021/09/27 15:44:02 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_pipex.h"
#include "../global/libft.h"

void	ft_exit_file(t_vars *vars)
{
	if (vars->fd1 >= 0)
		close(vars->fd1);
	if (vars->fd2 >= 0)
		close(vars->fd2);
	free(vars);
	ft_wrong_file();
}

void	ft_exit_args(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->fd1 >= 0)
		close(vars->fd1);
	if (vars->fd2 >= 0)
		close(vars->fd2);
	if (vars->arg1 != NULL)
		ft_free_3dtab(vars->arg1);
	if (vars->arg2 != NULL)
		ft_free_3dtab(vars->arg2);
	if (vars->path != NULL)
		ft_free_3dtab(vars->path);
	free(vars);
	ft_wrong_malloc();
}

void	ft_dup2_fail(t_vars *vars)
{
	int	i;

	i = 0;
	close(vars->fd1);
	close(vars->fd2);
	if (vars->arg1 != NULL)
		ft_free_3dtab(vars->arg1);
	if (vars->arg2 != NULL)
		ft_free_3dtab(vars->arg2);
	if (vars->path != NULL)
		ft_free_3dtab(vars->path);
	free(vars);
	perror("Error dup2, exiting with error code ");
	exit(EXIT_SUCCESS);
}

void	ft_exit_command(t_vars *vars)
{
	int	i;

	i = 0;
	close(vars->fd1);
	close(vars->fd2);
	if (vars->arg1 != NULL)
		ft_free_3dtab(vars->arg1);
	if (vars->arg2 != NULL)
		ft_free_3dtab(vars->arg2);
	if (vars->path != NULL)
		ft_free_3dtab(vars->path);
	free(vars);
	printf("Error, cannot access the requested command, exiting...\n");
	exit(EXIT_SUCCESS);
}

void	ft_exit_success(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->fd1 >= 0)
		close(vars->fd1);
	if (vars->fd2 >= 0)
		close(vars->fd2);
	if (vars->arg1 != NULL)
		ft_free_3dtab(vars->arg1);
	if (vars->arg2 != NULL)
		ft_free_3dtab(vars->arg2);
	if (vars->path != NULL)
		ft_free_3dtab(vars->path);
	free(vars);
	exit(EXIT_SUCCESS);
}
