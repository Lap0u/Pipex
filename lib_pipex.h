/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_pipex.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:30:36 by cbeaurai          #+#    #+#             */
/*   Updated: 2021/09/27 21:58:48 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PIPEX_H
# define LIB_PIPEX_H

# include "global/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <errno.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_vars
{
	char	**path;
	int		fd1;
	int		fd2;
	char	**arg1;
	char	**arg2;
}		t_vars;

char	**ft_get_paths(char **envp);

t_vars	*ft_setup_args(char **av, char **envp);

void	ft_exit_file(t_vars *vars);

void	ft_exit_args(t_vars *vars);

void	ft_exit_command(t_vars *vars);

void	ft_pipex(t_vars *vars, char **envp);

void	ft_1process(t_vars *vars, int end[2], char **envp);

void	ft_2process(t_vars *vars, int end[2], char **envp);

void	ft_dup2_fail(t_vars *vars);

char	*ft_rm_path(char *str);

void	ft_exit_success(t_vars *vars);

#endif
