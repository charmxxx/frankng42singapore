/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:13:42 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/07 23:13:46 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# define BUFFER_SIZE 1024

typedef struct s_record
{
	int		key;
	char	*val;
}	t_record;
char	**ft_split(const char *str, const char *sep);
void	ft_putchar(const char c);
void	ft_putstr(const char *str);
int		ft_atoi(const char *str);

#endif
