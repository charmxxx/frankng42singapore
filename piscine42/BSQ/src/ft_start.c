/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:55:03 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/10 20:55:05 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_get_width_check(char *st, int c, t_instr inf, int i)
{
	if (st[i] != inf.empty && st[i] != inf.obst)
		return (-1);
	else if (c == 2147483647)
		return (-1);
	return (0);
}

int	ft_get_width(char *st, t_instr inf, int width, int c)
{
	int		i;
	int		lines;

	i = inf.length - 1;
	lines = 0;
	while (st[++i])
	{
		if (st[i] == '\n')
		{
			if (width != -1 && width != c)
				return (-1);
			width = c;
			c = 0;
			lines++;
		}
		else if (st[i] != inf.empty && st[i] != inf.obst)
			return (-1);
		else if (c == 2147483647)
			return (-1);
		else
			c++;
	}
	if (lines == inf.height)
		return (width);
	return (-1);
}

void	ft_start(char *str)
{
	t_instr		*info;
	t_record	*record;
	int			width;

	info = ft_first_line(str);
	record = ft_new_record();
	if (info)
	{
		width = -1;
		info->width = ft_get_width(str, *info, width, 0);
		if (info->width > 0)
		{
			ft_get_record(info, str, record);
			ft_fill_board(record, str, info);
			ft_put_result(str, info->length);
			free(str);
		}
		else
			ft_putstr("map error\n");
	}
	else
		ft_putstr("map error\n");
}
