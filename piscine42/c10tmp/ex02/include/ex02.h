/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:34:45 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/10 21:28:35 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_H
# define EX02_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <libgen.h>
# include <errno.h>
# include <string.h>

void	ft_putstr(char *str);
void	print_err_msg(char *prog, char *file);
int		ft_atoi(char *str);

#endif
