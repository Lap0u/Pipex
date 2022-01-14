/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 12:13:54 by cbeaurai          #+#    #+#             */
/*   Updated: 2022/01/15 00:22:20 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_pipex.h"
#include "../global/libft.h"

char	*ft_add_slash(char *res)
{
	int		i;
	int		count;
	char	*str;

	i = 0;
	count = 0;
	while (res[i])
		if (res[i++] == ':')
			count++;
	str = malloc(sizeof(char) * ft_strlen(res) + count + 1);
	if (str == NULL)
		ft_wrong_malloc();
	i = 0;
	count = 0;
	while (res[i])
	{
		if (res[i] == ':')
			str[i + count++] = '/';
		str[i + count] = res[i];
		i++;
	}
	str[i + count] = '\0';
	return (str);
}

char	**ft_get_paths(char **envp)
{
	int		i;
	char	**res;
	int		j;
	char	*str;
	char	*temp;

	i = -1;
	while (envp[++i])
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			break ;
	if (envp[i] == NULL)
		return (NULL);
	j = 0;
	temp = ft_rm_path(envp[i]);
	if (temp == NULL)
		return (NULL);
	str = ft_add_slash(temp);
	res = ft_split(str, ':');
	free(str);
	free(temp);
	return (res);
}

void	ft_check_access(t_vars *vars)
{
	int		i;
	char	*temp;
	int		res;
	int		res2;

	i = -1;
	res = 0;
	res2 = 0;
	while (vars->path[++i])
	{
		temp = ft_strjoin(vars->path[i], vars->arg1[0]);
		if (temp == NULL)
			ft_exit_command(vars);
		if (access(temp, X_OK) == 0)
			res = 1;
		free(temp);
	}
	i = -1;
	while (vars->path[++i])
	{
		temp = ft_strjoin(vars->path[i], vars->arg2[0]);
		if (temp == NULL)
			ft_exit_command(vars);
		if (access(temp, X_OK) == 0)
			res2 = 1;
		free(temp);
	}
	if (res != 1 && res2 != 1)
		ft_exit_command(vars);
}

void	ft_add_path(t_vars *vars)
{
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
	while (vars->path[i])
	{
		temp = ft_strjoin(vars->path[i], vars->arg1[0]);
		temp2 = ft_strjoin(vars->path[i], vars->arg2[0]);
		if (access(temp, X_OK) == 0)
		{
			free(vars->arg1[0]);
			vars->arg1[0] = temp;
		}
		else
			free(temp);
		if (access(temp2, X_OK) == 0)
		{
			free(vars->arg2[0]);
			vars->arg2[0] = temp2;
		}
		else
			free(temp2);
		i++;
	}
}

int		is_only_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

t_vars	*ft_setup_args(char **av, char **envp)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (vars == NULL)
		ft_wrong_malloc();
	vars->fd2 = 0;
	vars->fd1 = ft_open_file_read(av[1]);
	vars->fd2 = ft_open_file_write_create(av[4]);
	if (vars->fd1 < 0 || vars ->fd2 < 0)
		ft_exit_file(vars);
	vars->path = ft_get_paths(envp);
	if (is_only_space(av[2]) == 1)
		vars->arg1 = ft_split(av[2], 'e');//e est choisi au hasard, on veut juste simuler un tableau de char* avec une seule chaine qui contient av[2] 
	else
		vars->arg1 = ft_split(av[2], ' ');
	if (is_only_space(av[3]) == 1)
		vars->arg2 = ft_split(av[3], 'e'); 
	else
		vars->arg2 = ft_split(av[3], ' ');
	ft_check_access(vars);
	ft_add_path(vars);
	if (vars->path == NULL || vars->arg1 == NULL || vars->arg2 == NULL)
		ft_exit_args(vars);
	return (vars);
}
