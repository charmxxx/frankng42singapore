unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	l;

	i = 0;
	while (src[i] != '\0' && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	l = i;
	while (src[l] != '\0') l++;
	while (i < size)
	{
		dest[i] = '\0';
		i++;
	}
	return (l);
}
