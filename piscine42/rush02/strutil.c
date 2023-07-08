/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:16:29 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/08 09:16:30 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*strcpy(char *dest, char *src)
{
	return (0);
}

int	ft_strlen(char *str)
{
	return (0);
}

int	ft_strslen(char **strs)
{
	int	count;

	count = 0;
	while (*strs != 0)
	{
		count++;
		strs++;
	}
	return (count);
}
