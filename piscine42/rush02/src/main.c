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

int	ft_error(const char *msg)
{
	ft_putstr((char *)msg);
	return (1);
}

int	main(int argc, char **argv)
{
	t_record	*dict;
	char		*key;

	if (argc < 2 || argc > 3)
		return (ft_error(DICT_ERROR));
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
		return (ft_error(DICT_ERROR));
	if (ft_convert(dict, key))
		ft_error(INVALID_NUMBER);
	ft_free_dict(dict);
}
