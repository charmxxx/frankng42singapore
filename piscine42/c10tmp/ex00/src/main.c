/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vietnguy <vietnguy@student.42singapore.sg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 11:17:59 by vietnguy          #+#    #+#             */
/*   Updated: 2023/07/09 11:50:12 by vietnguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 256
#define STDOUT 1
#define STDERR 2

void	ft_putstr(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
	write(fd, "\n", 1);
}

void	ft_display_file(char *filepath)
{
	int		fd;
	char	buf[BUF_SIZE];

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		ft_putstr(STDERR, "Error while opening the file.");
	else
	{
		while (read(fd, &buf, BUF_SIZE))
			ft_putstr(STDOUT, buf);
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_putstr(STDERR, "File name missing.");
	else if (argc > 2)
		ft_putstr(STDERR, "Too many arguments.");
	else
		ft_display_file(argv[1]);
	return (0);
}
