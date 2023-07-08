/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:16:29 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/08 13:02:49 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strcpy(char *dest, char *src)
{
	char	*destaddr;

	destaddr = dest;
	while (*src != 0)
		*dest++ = *src++;
	*dest = 0;	
	return (destaddr);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++ != 0)
		len++;
	return (len);
}

int	ft_strslen(char **strs)
{
	int	len;

	len = 0;
	while (*strs++ != 0)
		len++;
	return (len);
}
