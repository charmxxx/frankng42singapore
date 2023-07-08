/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:26:13 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/08 17:53:03 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdlib.h>

void	ft_printkv(long long key, char *val)
{
	if (key < 100)
		ft_putstr(val);
	else
	{
		ft_putstr("one ");
		ft_putstr(val);
	}
}

void	ft_eval_key(t_record *dict, long long key)
{
	int		i;
	long long	div;
	long long	mod;
	char		*val;

	val = ft_get_val(dict, key);
	if (val != NULL)
		return (ft_printkv(key, val));
	i = 0;
	while (dict[i].key > key &&  dict[i].val != 0)
		i++;
	div = key / dict[i].key;
	mod = key % dict[i].key;
	if (div == 1 && dict[i].key < 100)
		ft_putstr(dict[i].val);
	else
	{
		ft_eval_key(dict, div);
		ft_putstr(" ");
		ft_putstr(dict[i].val);
	}
	if (mod > 0)
	{
		ft_putstr(" ");
		ft_eval_key(dict, mod);
	}
}

void	ft_free_dict(t_record *dict)
{
	int	i;

	i = 0;
	while (dict[i].val != 0)
	{
		free(dict[i].val);
		i++;
	}
	free(dict);
}

char	*ft_get_val(t_record *dict, long long key)
{
	int	i;

	i = 0;
	while (dict[i].val != 0)
	{
		if (dict[i].key == key)
			return (dict[i].val);
		i++;
	}
	return (NULL);
}

int	ft_count_valid_dict_records(char **strs)
{
	int	count;

	count = 0;
	while (*strs != 0)
	{
		if (!ft_valid_dict_format(*strs))
			return (-1);
		count++;
		strs++;
	}
	return (count);
}
