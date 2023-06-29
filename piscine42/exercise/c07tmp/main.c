/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:11:04 by vietnguy          #+#    #+#             */
/*   Updated: 2023/06/29 16:15:32 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src);

int	main(int argc, char *argv[])
{
	char	*str;

	if (argc < 1)
		return (0);
	str = ft_strdup(argv[1]);
	printf("Output: \"%s\"\n", str);
	free(str);
	return (0);
}
