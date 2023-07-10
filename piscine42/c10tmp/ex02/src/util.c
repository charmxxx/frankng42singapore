/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:49:42 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/10 21:52:37 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex02.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	print_err_msg(char *prog, char *file)
{
	ft_putstr(basename(prog));
	ft_putstr(": ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}

int	ft_atoi(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result);
}
