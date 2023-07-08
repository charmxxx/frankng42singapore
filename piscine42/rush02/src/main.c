/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:59:34 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/08 17:50:37 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdlib.h>

int	ft_convert(t_record *dict, char *str)
{
	long long	key;

	if (!ft_valid_number(str))
		return (1);
	key = ft_atoi(str);
	ft_eval_key(dict, key);
	ft_putstr("\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_record	*dict;
	char		*key;

	dict = NULL;
	if (argc == 2)
	{
		dict = ft_parse_dict("numbers.dict");
		key = argv[1];
	}
	else if (argc == 3)
	{
		dict = ft_parse_dict(argv[1]);
		key = argv[2];
	}
	if (dict == NULL)
	{
		ft_putstr(DICT_ERROR);
		return (1);
	}
	if (ft_convert(dict, key))
		ft_putstr(INVALID_NUMBER);
	ft_free_dict(dict);
	return (0);
}
