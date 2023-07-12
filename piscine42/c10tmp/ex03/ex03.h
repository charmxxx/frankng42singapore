/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:39:21 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/11 21:59:31 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX03_H
# define EX03_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

typedef struct s_global
{
	char	*g_prog;
	char	*g_buf;
	char	*g_hex;
	int		g_is_on_flag_c;
	int		g_duplicated;
	int		g_offset;
	int		g_cnt;
	char	*g_buf_prev;
	int		g_last_lines;
	int		g_bfd;
}	t_global;

void	ft_putchar(unsigned char c);
void	ft_putstr(char *str);
void	print_input_offset(t_global *g, int n, int offset);
void	print_hexadecimal_bytes(t_global *g, char *str, int size);
void	print_characters(char *str, int len);
void	print_error_msg(t_global *g, char *file);
void	print(t_global *g);
void	hexdump_stdin(t_global *g);
void	hexdump_files(t_global *g, int argc, char *argv[]);
void	init_other_g_vars(t_global *g);
int		is_printable(unsigned char c);
int		is_flag_c(char *str);
int		ft_is_equal(char *a, char *b);
int		ft_is_equal(char *a, char *b);
#endif
