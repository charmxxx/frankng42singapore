/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:39:29 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/11 21:39:30 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex03.h"

void	handle_last_lines(t_global *g)
{
	if (g->g_cnt)
	{
		print_input_offset(g, 7, g->g_offset);
		print_hexadecimal_bytes(g, g->g_buf, 8 * (g->g_cnt / 8) + g->g_cnt);
		print_hexadecimal_bytes(g, g->g_buf + 8, g->g_cnt - 8);
		if (g->g_is_on_flag_c)
			print_characters(g->g_buf, g->g_cnt);
		ft_putchar('\n');
	}
	print_input_offset(g, 7, g->g_offset + g->g_cnt);
	ft_putchar('\n');
}

int	main(int argc, char *argv[])
{
	t_global	g;

	g.g_prog = argv[0];
	init_other_g_vars(&g);
	if (argc >= 2 && is_flag_c(argv[1]))
		g.g_is_on_flag_c = 1;
	if (argc == 1 + g.g_is_on_flag_c)
		hexdump_stdin(&g);
	else
		hexdump_files(&g, argc, argv);
	if (g.g_last_lines)
		handle_last_lines(&g);
	free(g.g_buf);
	free(g.g_buf_prev);
	return (0);
}
