/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dict.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 22:54:20 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/07 22:54:21 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "rush02.h"

void	ft_free(char **str)
{
	while(*str != 0)
	{
		free(*str);
		str++;
	}
	free(str);
}

int	ft_parse_dict(const char *filepath)
{
	const int	fd = open(filepath, O_RDONLY);
	size_t		bytes;
	char		buf[BUFFER_SIZE];
	char		**lines;

	if (fd < 0)
		return (1);
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		lines = ft_split(buf, "\n");
	}
	ft_free(lines);
	if (close(fd) < 0)
		return (1);
	return (0);
}

int	main(void)
{
	ft_parse_dict("numbers.dict");
}
