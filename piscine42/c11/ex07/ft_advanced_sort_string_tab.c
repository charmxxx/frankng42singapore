/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:39:57 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/12 21:40:23 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_tab_size(char **tab)
{
	int	ret;

	ret = 0;
	while (tab[ret])
		++ret;
	return (ret);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		size;
	char	*tmp;

	size = ft_get_tab_size(tab);
	i = 1;
	while (i++ < size)
	{
		j = 0;
		while (++j < size)
		{
			if (cmp(tab[j - 1], tab[j]) > 0)
			{
				tmp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = tmp;
			}
		}
	}
}
/*
#include <stdio.h>
#include <stdlib.h>
int	cmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s2 - *s1);
}

int	main(void)
{
        char    **test;

        test = (char **)malloc(6 * sizeof(char *));
        for (int i = 0; i < 5; i++)
                test[i] = (char *)malloc(20 * sizeof(char));
        test[0] = "Zealot";
        test[1] = "ABC";
        test[2] = "CD Man";
        test[3] = "Baby Drool";
        test[4] = "x0x";
        test[5] = 0;
        ft_advanced_sort_string_tab(test, &cmp);
        for(int i = 0; i < 5; i++)
                printf("%s\n", test[i]);
}
*/
