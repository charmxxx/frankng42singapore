/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 22:54:20 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/08 13:07:54 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "rush02.h"

t_record	*ft_init_dict(char **lines)
{
	t_record	*dict;
	int			len;
	int			i;
	char		**kv;

	len = ft_strslen(lines);
	dict = (t_record *)malloc((len + 1) * sizeof(t_record));
	i = 0;
	while (*lines != 0)
	{
		kv = ft_split(*lines, " :");
		dict[i].key = (char *)malloc((ft_strlen(kv[0]) + 1) * sizeof(char));
		dict[i].val = (char *)malloc((ft_strlen(kv[1]) + 1) * sizeof(char));
		ft_strcpy(dict[i].key, kv[0]);
		ft_strcpy(dict[i].val, kv[1]);
		ft_free_strs(kv);
	}
	dict[len].val = 0;
	return (dict);
}

int	ft_parse_dict(char *filepath)
{
	const int	fd = open(filepath, O_RDONLY);
	size_t		bytes;
	char		buf[BUFFER_SIZE];
	char		**lines;
	t_record	*dict;

	if (fd < 0)
		return (1);
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes <= 0)
		return (1);
	lines = ft_split(buf, "\n");
	dict = ft_init_dict(lines);
	ft_print_dict(dict);
	ft_free_dict(dict);
	ft_free_strs(lines);
	if (close(fd) < 0)
		return (1);
	return (0);
}
