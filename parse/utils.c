/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:17:59 by cbeaurai          #+#    #+#             */
/*   Updated: 2021/09/28 12:37:32 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global/libft.h"
#include "../lib_pipex.h"

char	*ft_rm_path(char *str)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * ft_strlen(str) - 3);
	if (res == NULL)
		return (NULL);
	while (str[i + 5])
	{
		res[i] = str[i + 5];
		i++;
	}
	res[i] = '/';
	res[i + 1] = '\0';
	return (res);
}
