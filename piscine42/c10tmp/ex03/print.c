/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:39:36 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/11 21:39:37 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex03.h"

void	print(t_global *g)
{
	g->g_last_lines = 1;
	if (ft_is_equal(g->g_buf, g->g_buf_prev))
	{
		if (!g->g_duplicated)
		{
			g->g_duplicated = 1;
			ft_putstr("*\n");
		}
	}
	else
	{
		g->g_duplicated = 0;
		print_input_offset(g, 7, g->g_offset);
		print_hexadecimal_bytes(g, g->g_buf, 8 * (g->g_cnt / 8) + g->g_cnt);
		print_hexadecimal_bytes(g, g->g_buf + 8, g->g_cnt - 8);
		if (g->g_is_on_flag_c)
			print_characters(g->g_buf, g->g_cnt);
		ft_putchar('\n');
		free(g->g_buf_prev);
		g->g_buf_prev = g->g_buf;
		g->g_buf = (char *)malloc(17);
	}
	g->g_offset += 16;
	g->g_cnt = 0;
}

void	print_input_offset(t_global *g, int n, int offset)
{
	if (!offset)
	{
		n += g->g_is_on_flag_c;
		while (n--)
			ft_putchar('0');
		return ;
	}
	print_input_offset(g, n - 1, offset >> 4);
	ft_putchar(g->g_hex[(offset & 15)]);
}

void	print_hexadecimal_bytes(t_global *g, char *str, int size)
{
	int	i;
	int	tmp;

	if (g->g_is_on_flag_c)
		ft_putchar(' ');
	i = 0;
	while (i < size && i < 8)
	{
		ft_putchar(' ');
		tmp = str[i];
		ft_putchar(g->g_hex[(tmp / 16)]);
		ft_putchar(g->g_hex[(tmp % 16)]);
		++i;
	}
	while (i++ < 8)
		ft_putstr("   ");
}

void	print_characters(char *str, int len)
{
	int	i;

	ft_putstr("  |");
	i = 0;
	while (i < len)
	{
		if (is_printable(str[i]))
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		++i;
	}
	ft_putchar('|');
}

void	print_error_msg(t_global *g, char *file)
{
	ft_putstr(basename(g->g_prog));
	ft_putstr(": ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putchar('\n');
	errno = 0;
}
