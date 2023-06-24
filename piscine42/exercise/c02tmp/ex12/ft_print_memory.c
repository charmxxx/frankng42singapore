#include <stdint.h>
#include <unistd.h>
#include <stdio.h>

void	uint64_to_hex_str(uint64_t n, unsigned char *str)
{
	const uint8_t	hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	int	i;

	str[16] = '\0';
	i = 15;
	while (i >= 0)
	{
		str[i] = hex[n & 0x0f];
		n >>= 4;
		i--;
	}
}

void	uint8_to_hex_str(uint8_t n, unsigned char *str)
{
	const uint8_t	hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	str[0] = hex[(n >> 4) & 0x0f];
	str[1] = hex[n & 0x0f];
	str[2] = '\0';
}

void	print_str(unsigned char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

uint8_t	is_printable(unsigned char c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}

void	print_mem_chars(unsigned char *str, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		if (is_printable(str[i]))
		{
			write(1, &str[i], 1);
		}
		else
		{
			write(1, ".", 1);
		}
		i++;
	}
}

void	print_mem_address(void *loc)
{
	unsigned char	str[17];

	uint64_to_hex_str((uint64_t)loc, str);
	print_str(str);
}

void	print_mem_hex(void *loc)
{
	int	i;
	unsigned char	str[3];

	i = 0;
	while (i < 16)
	{
		uint8_to_hex_str(*(uint8_t *)(loc + i), str);
		print_str(str);
		if (i % 2 == 1)
		{
			write(1, " ", 1);
		}
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	line;
	void			*loc;

	loc = addr;
	line = 0;
	while (line <  size)
	{
		// print the address of the segment
		print_mem_address(loc);
		write(1, ": ", 2);
		// print the hex of the segment
		print_mem_hex(loc);
		// print the content of the segment in printable characters
		print_mem_chars(loc, 16);

		write(1, "\n", 1);
		loc += 16;
		line++;
	}

	return (addr);
}

int main()
{
	char *str = "hello world!!!!!!!!!!!!!!!!!!!!";


	ft_print_memory((void *)str, 5);
}
