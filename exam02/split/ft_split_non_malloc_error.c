#include <stdlib.h>

int ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

int ft_count_words(char *str)
{
	int i = 0;
	int count = 0;

	while(ft_isspace(str[i]))
		i++;
	while (str[i])
	{
		if (!ft_isspace(str[i]) && ft_isspace(str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

int ft_strlen_sp(char *str)
{
	int i = 0;

	while (!ft_isspace(str[i]))
		i++;
	return (i);
}

char *ft_word(char *str)
{
	char *word;
	int j = 0;
	int len;

	len = ft_strlen_sp(str);
	word = (char *)malloc(sizeof(char) * (len + 1));
	while (j < len)
	{
		word[j] = str[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char **ft_split(char *str)
{
	char **res;
	int i = 0;
	int count;

	if (!str)
		count = 0;
	else 
		count = ft_count_words(str);
	res = (char **)malloc(sizeof(char *) * (count + 1));
	while (i < count)
	{
		while (ft_isspace(*str))
			str++;
		res[i] = ft_word(str);
			i++;
		while (!ft_isspace(*str))
			str++;
	}
	res[i] = NULL;
	return (res);
}

#ifdef test

#include <stdio.h>

int main(int argc, char **argv)
{
	char **res;
	int i = 0;
	char *str = "\tapple pie apple\n \tpie\tapple   \n";

//	if (argc != 2)
//		return (1);
	(void)argc;
	(void)argv;
//	res = ft_split(argv[1]);
	res = ft_split(str);
	while (res[i])
		printf("%s\n", res[i++]);
 return (0);
} 

#endif
