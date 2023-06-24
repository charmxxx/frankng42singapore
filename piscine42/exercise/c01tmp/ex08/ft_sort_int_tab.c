void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	char	found;

	found = 1;
	while (found)
	{
		j = 1;
		found = 0;
		while (j < size)
		{
			if (tab[j - 1] > tab[j])
			{
				swap(&tab[j - 1], &tab[j]);
				found = 1;
			}
			j++;
		}
	}
}
