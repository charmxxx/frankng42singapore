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
	int	g_is_on_flag_c;
	int	g_duplicated;
	int	g_offset;
	int	g_cnt;
	char	*g_buf_prev;
	int	g_last_lines;
}	t_global;
int		is_printable(unsigned char c);
void	ft_putchar(unsigned char c);
void	ft_putstr(char *str);
void	print_input_offset(int n, int offset);
void	print_hexadecimal_bytes(char *str, int size);
void	print_characters(char *str, int len);
void	print_error_msg(char *file);
int		is_flag_c(char *str);
void	print(void);
int		ft_is_equal(char *a, char *b);

#endif
