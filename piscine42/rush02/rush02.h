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
	char	*key;
	char	*val;
}	t_record;
/* strio.c */
void	ft_putchar(char c);
void	ft_putstr(char *str);
/* strutil.c */
int		ft_strlen(char *str);
int		ft_strslen(char **strs);
char	*strcpy(char *dest, char *src);
/* strconv.c */
int		ft_atoi(char *str);
/* strsplit.c */
char	**ft_split(char *str, char *sep);
/* stralloc.c */
void	ft_free_strs(char **strs);
/* dict.c */
void	ft_free_dict(t_record *dict);
#endif
