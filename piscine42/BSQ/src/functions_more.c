/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:54:45 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/10 20:54:46 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_bsq.h"

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
}

void	ft_put_result(char *str, int start)
{
	int		i;
	ssize_t	ret;

	i = 0;
	while (str[start + i])
		i++;
	ret = write(1, &str[start], i);
	if (ret < 0)
		ft_putstr("Error in Write");
}
