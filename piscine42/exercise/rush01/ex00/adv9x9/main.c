/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:22:29 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/02 10:27:54 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include <stdio.h>

void	try(int i, int j, t_boardstat *s);

void	next(int i, int j, t_boardstat *s)
{
	if (s->mat[i][j + 1] == 0)
		try(i, j + 1, s);
	else if (s->mat[i + 1][j] == 0)
		try(i + 1, j, s);
	else if (s->mat[i][j - 1] == 0)
		try(i, j - 1, s);
	else if (s->mat[i - 1][j] == 0)
		try(i - 1, j, s);
	else
	{
		s->found = 1;
		ft_print_matrix(s);
	}
}

void	ft_addviews(int i, int j, int h, t_boardstat *s)
{
	if (s->mleft[i][j - 1] > 0 && h > s->mleft[i][j - 1])
	{
		s->mleft[i][j] = h;
		s->cleft[i]++;
	}
	else
		s->mleft[i][j] = s->mleft[i][j - 1];
	if (s->mright[i][j + 1] > 0 && h > s->mright[i][j + 1])
	{
		s->mright[i][j + 1] = h;
		s->cright[i]++;
	}
	else
		s->mright[i][j] = s->mright[i][j + 1];
	if (s->mup[i - 1][j] > 0 && h > s->mup[i - 1][j])
	{
		s->mup[i][j] = h;
		s->cup[j]++;
	}
	else
		s->mup[i][j] = s->mup[i - 1][j];
	if (s->mdown[i + 1][j] > 0 && h > s->mdown[i + 1][j])
	{
		s->mdown[i + 1][j] = h;
		s->cdown[j]++;
	}
	else
		s->mdown[i][j] = s->mdown[i + 1][j];

}

void	ft_dropviews(int i, int j, int h, t_boardstat *s)
{
        if (s->mleft[i][j - 1] > 0 && h > s->mleft[i][j - 1])
                s->cleft[i]--;
        s->mleft[i][j] = s->mleft[i][j - 1];
        if (s->mright[i][j + 1] > 0 && h > s->mright[i][j + 1])
                s->cright[i]--;
        s->mright[i][j] = s->mright[i][j + 1];
        if (s->mup[i - 1][j] > 0 && h > s->mup[i - 1][j])
                s->cup[j]--;
        s->mup[i][j] = s->mup[i - 1][j];
        if (s->mdown[i + 1][j] > 0 && h > s->mdown[i + 1][j])
                s->cdown[j]--;
        s->mdown[i][j] = s->mdown[i + 1][j];
}

void	try(int i, int j, t_boardstat *s)
{
	int		h;

	if (s->found)
		return ;
	h = 1;
	while (h <= s->size)
	{
		s->mat[i][j] = h;
		ft_addviews(i, j, h, s);
		if (ft_valid_case(i, j, h, s))
		{
			s->col_used[j][h] = 1;
			s->row_used[i][h] = 1;
			next(i, j, s);
			s->col_used[j][h] = 0;
			s->row_used[i][h] = 0;
		}
		ft_dropviews(i, j, h, s);
		h++;
	}	
	s->mat[i][j] = 0;
}

int	main(int argc, char *argv[])
{
	t_boardstat	s_stat;

	s_stat.size = BOARD_SIZE;
	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	ft_readview(argv[1], &s_stat);
	ft_initialize(&s_stat);
	s_stat.found = 0;
	try(1, 1, &s_stat);
	if (!s_stat.found)
		ft_putstr("Error\n");
	return (0);
}
