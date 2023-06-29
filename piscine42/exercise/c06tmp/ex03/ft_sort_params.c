/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:58:22 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/29 11:58:28 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != 0)
		write(1, str++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != 0 && *s2 != 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_strcpy(char *dest, char *src)
{
	while (*src != 0)
		*dest++ = *src++;
	*dest = 0;
}

void	ft_sort(char *s[], int l, int r)
{
	int		found;
	int		i;
	char	*tmp;

	while (1)
	{
		found = 0;
		i = l;
		while (i < r)
		{
			if (ft_strcmp(s[i], s[i + 1]) > 0)
			{
				ft_strcpy(tmp, s[i]);
				ft_strcpy(s[i], s[i + 1]);
				ft_strcpy(s[i + 1], tmp);
				found = 1;
			}
			i++;
		}
		if (!found)
			break;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	ft_sort(argv, 0, argc - 1);
	i = 0;
	while (i < argc)
	{
		ft_putstr((char *)argv[i]);
		ft_putstr("\n");
		i++;
	}
	return (0);
}
