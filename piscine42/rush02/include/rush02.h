/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:13:42 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/08 13:07:28 by vietnguy         ###   ########.fr       */
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
/* parse_dict.c */
int	ft_parse_dict(char *filepath);
/* strio.c */
void	ft_putchar(char c);
void	ft_putstr(char *str);
/* strutil.c */
int		ft_strlen(char *str);
int		ft_strslen(char **strs);
char	*ft_strcpy(char *dest, char *src);
/* strconv.c */
int		ft_atoi(char *str);
/* strsplit.c */
int	ft_count_words(char *str, char *sep);
char	**ft_split(char *str, char *sep);
/* stralloc.c */
void	ft_free_strs(char **strs);
/* dict.c */
void	ft_free_dict(t_record *dict);
void	ft_print_dict(t_record *dict);
#endif
