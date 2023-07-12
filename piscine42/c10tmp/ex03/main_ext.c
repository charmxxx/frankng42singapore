/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:16:59 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/12 15:31:02 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex03.h"

int	ft_is_equal(char *a, char *b)
{
	int	i;

	i = -1;
	while (++i < 16)
		if (a[i] != b[i])
			return (0);
	return (1);
}

void	hexdump_stdin(t_global *g)
{
	while (read(0, &g->g_buf[g->g_cnt], 1))
		if (++g->g_cnt == 16)
			print(g);
}

void	handle_file(t_global *g, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		print_error_msg(g, filename);
		return ;
	}
	while (read(fd, &g->g_buf[g->g_cnt], 1))
	{
		g->g_bfd = 0;
		if (errno)
		{
			print_error_msg(g, filename);
			return ;
		}
		if (++g->g_cnt == 16)
			print(g);
	}
}

void	hexdump_files(t_global *g, int argc, char *argv[])
{
	int	i;

	i = g->g_is_on_flag_c;
	while (++i < argc)
		handle_file(g, argv[i]);
	if (g->g_bfd)
	{
		errno = 9;
		print_error_msg(g, argv[argc - 1]);
	}
}

void	init_other_g_vars(t_global *g)
{
	g->g_hex = "0123456789abcdef";
	g->g_is_on_flag_c = 0;
	g->g_last_lines = 0;
	g->g_offset = 0;
	g->g_cnt = 0;
	g->g_bfd = 1;
	g->g_duplicated = 0;
	g->g_buf_prev = (char *)malloc(17);
	g->g_buf = (char *)malloc(17);
}
