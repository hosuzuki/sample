bool	ft_is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int		ft_count_alpha_recursive_count(char *str, char target)
{
	int		count;
	char	now;

	count = 0;
	while ((now = *str))
	{
		if (ft_is_uppercase(now))
			now += CASE_OFFSET;
		if (target == now)
			count++;
		str++;
	}
	return (count);
}

void	ft_count_alpha_print(int app[LETTER_COUNT + 1],
				char order[LETTER_COUNT + 1])
{
	int	i;
	int	size;

	size = 0;
	while (order[size] != '\0')
		size++;
	i = 0;
	while (i < size)
	{
		printf("%d%c", app[order[i] - 'a'], order[i]);
		if (i != size - 1)
			printf(", ");
		i++;
	}
}

char	ft_count_alpha_validate(char c, int app[LETTER_COUNT + 1])
{
	if (!ft_is_uppercase(c) && !((c >= 'a' && c <= 'z')))
		return ('\0');
	if (ft_is_uppercase(c))
		c += CASE_OFFSET;
	if (app[(int)c - 'a'] != NOT_COUNTED_YET)
		return ('\0');
	return (c);
}

void	ft_count_alpha(char *str)
{
	int		i;
	int		app[LETTER_COUNT + 1];
	char	app_order[LETTER_COUNT + 1];
	char	now;

	i = 0;
	while (i < LETTER_COUNT + 1)
	{
		app[i] = NOT_COUNTED_YET;
		app_order[i] = '\0';
		i++;
	}
	i = 0;
	while (*str)
	{
		now = ft_count_alpha_validate(*str, app);
		if (now != '\0')
		{
			app[(int)now - 'a'] = ft_count_alpha_recursive_count(str, now);
			app_order[i] = now;
			i++;
		}
		str++;
	}
	ft_count_alpha_print(app, app_order);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_count_alpha(argv[1]);
	printf("\n");
}
