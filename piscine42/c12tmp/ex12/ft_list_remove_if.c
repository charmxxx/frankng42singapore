/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:25:09 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/13 14:35:58 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	free_curr(t_global *g, void (*free_fct)(void *))
{
	free_fct(g->g_curr->data);
	free(g->g_curr);
}

void	slide_next(t_global *g)
{
	g->g_prev = g->g_curr;
	g->g_curr = g->g_curr->next;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_global	g;

	g.g_curr = *begin_list;
	while (g.g_curr && (cmp(g.g_curr->data, data_ref) == 0))
	{
		*begin_list = g.g_curr->next;
		free_curr(&g, free_fct);
		g.g_curr = *begin_list;
	}
	if (!g.g_curr || !g.g_curr->next)
		return ;
	slide_next(&g);
	while (g.g_curr)
	{
		if (cmp(g.g_curr->data, data_ref) == 0)
		{
			g.g_tmp = g.g_curr->next;
			free_curr(&g, free_fct);
			g.g_prev->next = g.g_tmp;
			g.g_curr = g.g_tmp;
		}
		else
			slide_next(&g);
	}
}
