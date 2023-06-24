int	is_alphabet(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	char	is_first_letter;
	int		i;

	i = 0;
	is_first_letter = 1;
	while (str[i] != '\0')
	{
		if (is_alphabet(str[i]))
		{
			str[i] = to_lower(str[i]);
			if (is_first_letter)
			{
				str[i] = to_upper(str[i]);
				is_first_letter = 0;
			}
		}
		else if (str[i] == ' ')
		{
			is_first_letter = 1;
		}
		i++;
	}
	return (str);
}
