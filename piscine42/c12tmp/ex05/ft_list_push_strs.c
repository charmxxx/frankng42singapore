/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:17:50 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/13 14:17:56 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*ret;
	t_list	*tmp;
	int		i;

	ret = 0;
	i = -1;
	while (++i < size)
	{
		tmp = ret;
		ret = ft_create_elem(strs[i]);
		ret->next = tmp;
	}
	return (ret);
}
