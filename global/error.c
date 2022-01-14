/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbeaurai <cbeaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:51:59 by cbeaurai          #+#    #+#             */
/*   Updated: 2021/09/26 00:56:25 by cbeaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_wrong_file(void)
{
	printf("Error while opening file, exiting...\n");
	exit(EXIT_SUCCESS);
}

void	ft_wrong_arg(void)
{
	printf("Error, wrong argument, exiting...\n");
	exit(EXIT_SUCCESS);
}

void	ft_wrong_env(void)
{
	printf("Error, PATH variable couldn't be found, exiting...\n");
	exit(EXIT_SUCCESS);
}

void	ft_wrong_malloc(void)
{
	printf("Error, malloc couldn't allocate memory accordingly, exiting...\n");
	exit(EXIT_SUCCESS);
}
