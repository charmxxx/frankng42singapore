/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:25:44 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/02 10:29:19 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H
# define BOARD_SIZE 9
typedef struct s_boardstat
{
	int	col_used[11][11];
	int	row_used[11][11];
	int	mat[11][11];
	int	upview[11];
	int	downview[11];
	int	leftview[11];
	int	rightview[11];
	int	cleft[11];
	int	cright[11];
	int	cup[11];
	int	cdown[11];
	int	mleft[11][11];
	int	mright[11][11];
	int	mup[11][11];
	int	mdown[11][11];
	int	size;
	int	found;
}	t_boardstat;
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_print_matrix(t_boardstat *s);
void	ft_do_readview(char **argv, int *view, int size);
void	ft_readview(char *argv, t_boardstat *s);
int		ft_valid_case(int i, int j, int h, t_boardstat *s);
void	ft_initialize(t_boardstat *s);
#endif
