/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 09:26:13 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/08 15:38:45 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdlib.h>

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

void	ft_print_dict(t_record *dict)
{
	int	i;

	i = 0;
	while (dict[i].val != 0)
	{
		ft_putstr("key:");
		ft_putnbr(dict[i].key);
		ft_putstr(",val:");
		ft_putstr(dict[i].val);
		ft_putstr("\n");
		i++;
	}
}

char	*ft_get_val(t_record *dict, int key)
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
