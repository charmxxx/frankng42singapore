/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:59:34 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/08 15:43:29 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdlib.h>

int	ft_convert(t_record *dict, char *str)
{
	int	key;
	char	*val;

	if (!ft_valid_number(str))
		return (1);
	key = ft_atoi(str);
	val = ft_get_val(dict, key);
	if (val == NULL)
		return (1);
	ft_putstr(val);
	ft_putstr("\n");
	return (0);
}

int	ft_error(void)
{
	ft_putstr(ERR_MSG);
	return (1);
}

int	main(int argc, char **argv)
{
	t_record	*dict;
	char		*key;

	if (argc < 2 || argc > 3)
		return (ft_error());
	if (argc == 2)
	{
		dict = ft_parse_dict("numbers.dict");
		key = argv[1];
	}
	else
	{
		dict = ft_parse_dict(argv[1]);
		key = argv[2];
	}
	if (dict == NULL)
		return (ft_error());
	if (ft_convert(dict, key))
		ft_error();
	ft_free_dict(dict);
}
