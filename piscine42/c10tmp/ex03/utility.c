/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:39:43 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/11 21:39:44 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex03.h"

int	is_printable(unsigned char c)
{
	return (' ' <= c && c <= '~');
}

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}

int	is_flag_c(char *str)
{
	return (str[0] == '-' && str[1] == 'C');
}
