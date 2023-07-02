/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 20:39:16 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/02 10:26:46 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

int	ft_valid_case(int i, int j, int h, t_boardstat *s)
{
	if (s->col_used[j][h] || s->row_used[i][h])
		return (0);
	if (s->cleft[i] > s->leftview[i])
		return (0);
	if (s->cright[i] > s->rightview[i])
		return (0);
	if (s->cup[j] > s->upview[j])
		return (0);
	if (s->cdown[j] > s->downview[j])
		return (0);
	if (s->size - s->mleft[i][j] + s->cleft[i] < s->leftview[i])
		return (0);
	if (s->size - s->mright[i][j] + s->cright[i] < s->rightview[i])
		return (0);
	if (s->size - s->mup[i][j] + s->cup[j] < s->upview[j])
		return (0);
	if (s->size - s->mdown[i][j] + s->cdown[j] < s->downview[j])
		return (0);
	return (1);
}

void	ft_init_mat(t_boardstat *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < 11)
	{
		j = 0;
		while (j < 11)
		{
			s->mat[i][j] = -1;
			s->col_used[i][j] = 0;
			s->row_used[i][j] = 0;
			s->mup[i][j] = 0;
			s->mdown[i][j] = 0;
			s->mleft[i][j] = 0;
			s->mright[i][j] = 0;
			j++;
		}
		s->cup[i] = 0;
		s->cdown[i] = 0;
		s->cleft[i] = 0;
		s->cright[i] = 0;
		i++;
	}
}

void	ft_initialize(t_boardstat *s)
{
	int	i;
	int	j;

	ft_init_mat(s);
	i = 1;
	while (i <= s->size)
	{
		j = 1;
		while (j <= s->size)
		{
			s->mat[i][j] = 0;
			j++;
		}
		i++;
	}
}
