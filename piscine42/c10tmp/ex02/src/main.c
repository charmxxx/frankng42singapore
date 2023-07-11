/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:29:13 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/11 21:32:15 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex02.h"

void	clean_stdin(void)
{
	char	buf;

	while (read(0, &buf, 1))
		if (errno)
			return ;
}

void	display_file(int fd, int size)
{
	long long	idx;
	char		*buf;
	int			tmp;

	if (size == 0)
		clean_stdin();
	else
	{
		buf = (char *)malloc(size * sizeof(char));
		idx = 0;
		while (read(fd, &buf[idx % size], 1))
		{
			if (errno)
				return ;
			idx++;
		}
		tmp = idx % size;
		if (idx >= size)
			write(1, buf + tmp, size - tmp);
		write(1, buf, tmp);
		free(buf);
	}
}

void	print_title(int newline, char *filename)
{
	if (newline)
		ft_putstr("\n");
	ft_putstr("==> ");
	ft_putstr(filename);
	ft_putstr(" <==");
}

void	display(int argc, char **argv, int size)
{
	int	i;
	int	j;
	int	fd;

	i = 2;
	j = 0;
	while (++i < argc)
	{
		errno = 0;
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			print_err_msg(argv[0], argv[i]);
			continue ;
		}
		if (argc > 4)
			print_title(j, argv[i]);
		j = 1;
		display_file(fd, size);
		close(fd);
	}
}

int	main(int argc, char **argv)
{
	int	size;

	size = ft_atoi(argv[2]);
	if (size == 0)
		return (0);
	if (argc == 3)
		display_file(0, size);
	else
		display(argc, argv, size);
	return (0);
}
