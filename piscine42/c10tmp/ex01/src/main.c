/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:20:45 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/09 15:20:57 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

#define BUF_SIZE 1

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	print_err_msg(char *prog, char *file)
{
	ft_putstr(basename(prog));
	ft_putstr(": ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	errno = 0;
}

void	display_file(int fd, char *prog, char *file)
{
	unsigned char	buf[BUF_SIZE];
	long			size;

	while (1)
	{
		size = read(fd, buf, BUF_SIZE);
		if (size <= 0)
			break;
		if (errno)
		{
			print_err_msg(prog, file);
			return ;
		}
		write(1, buf, size);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*prog;

	prog = argv[0];
	i = 0;
	if (argc == 1)
		display_file(0, 0, 0);
	else
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd == -1)
			{
				print_err_msg(prog, argv[i]);
				continue ;
			}
			display_file(fd, prog, argv[i]);
			close(fd);
		}
	return (0);
}
