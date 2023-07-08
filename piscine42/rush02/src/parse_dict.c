/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 22:54:20 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/08 18:25:06 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "rush02.h"

char		*ft_parse_val(char *val)
{
	int	l;
	int	r;
	int	i;
	char	*str;

	l = 0;
	while (val[l] == ' ')
		l++;
	r = ft_strlen(val) - 1;
	while (val[r] == ' ')
		r--;
	str = (char *)malloc((r - l + 2) * sizeof(char));
	i = 0;
	while (l <= r)
	{
		str[i] = val[l];
		i++;
		l++;
	}
	str[i] = 0;
	return (str);
}

t_record	*ft_dict_from_strs(char **strs)
{
	t_record	*dict;
	int			len;
	int			i;
	char		**kv;

	len = ft_strslen(strs);
	dict = (t_record *)malloc((len + 1) * sizeof(t_record));
	i = 0;
	while (*strs != 0)
	{
		kv = ft_split(*strs, ":");
		dict[i].key = ft_atoi(kv[0]);
		dict[i].val = ft_parse_val(kv[1]);
		ft_free_strs(kv);
		strs++;
		i++;
	}
	dict[len].val = 0;
	return (dict);
}

t_record	*ft_parse_dict(char *filepath)
{
	const int	fd = open(filepath, O_RDONLY);
	size_t		bytes;
	char		buf[BUFFER_SIZE];
	char		**lines;
	t_record	*dict;

	if (fd < 0)
		return (NULL);
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes <= 0)
		return (NULL);
	lines = ft_split(buf, "\n");
	dict = ft_dict_from_strs(lines);
	ft_sortdict(dict);
	ft_free_strs(lines);
	if (close(fd) < 0)
	{
		ft_free_dict(dict);
		return (NULL);
	}
	return (dict);
}
