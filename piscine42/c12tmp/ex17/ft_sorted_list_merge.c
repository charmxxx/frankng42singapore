/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:43:59 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/13 14:49:52 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	init(t_g *g, t_list *begin_list1, t_list *begin_list2, int (*cmp)())
{
	if (cmp(begin_list1->data, begin_list2->data) > 0)
	{
		g->g_l = begin_list1;
		g->g_r = begin_list2->next;
		g->g_head = begin_list2;
	}
	else
	{
		g->g_l = begin_list1->next;
		g->g_r = begin_list2;
		g->g_head = begin_list1;
	}
	g->g_tmp = g->g_head;
}

int	is_null(t_list **begin_list1, t_list *begin_list2)
{
	if (!begin_list2)
		return (1);
	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return (1);
	}
	return (0);
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_g	g;

	if (is_null(begin_list1, begin_list2))
		return ;
	init(&g, *begin_list1, begin_list2, cmp);
	*begin_list1 = g.g_head;
	while (g.g_l && g.g_r)
	{
		if (cmp(g.g_l->data, g.g_r->data) > 0)
		{
			g.g_tmp->next = g.g_r;
			g.g_r = g.g_r->next;
		}
		else
		{
			g.g_tmp->next = g.g_l;
			g.g_l = g.g_l->next;
		}
		g.g_tmp = g.g_tmp->next;
	}
	if (g.g_l)
		g.g_tmp->next = g.g_l;
	if (g.g_r)
		g.g_tmp->next = g.g_r;
}
