#include <unistd.h>

void	write_hexadecimal(char c)
{
	const unsigned char	hex[] = "0123456789abcdef";
	unsigned char		str[3];

	str[0] = '\\';
	str[1] = hex[c >> 4];
	str[2] = hex[c & 0x0f];
	write(1, str, 3);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, str[i], 1);
		write_hexadecimal(str[i]);
	}
}
