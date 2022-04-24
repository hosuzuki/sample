#include "get_next_line.h"

char	*ft_strchar(char *str, int c)
{
	size_t	i = 0;

	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		if(str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

size_t ft_strlen(char	*str)
{
	size_t i = 0;
	
	if (str == NULL)
		return (0);
	while(str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char	*buf, char *b)
{
	int i = 0;
	int j = 0;
	int len1;
	int len2;
	char *new;

	len1 = ft_strlen(buf);
	len2 = ft_strlen(b);
	new = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new)
		return (NULL);
	if (buf != NULL)
	{
		while (buf[i])
		{
			new[i] = buf[i];
			i++;
		}
	}
	if (b != NULL)
	{
		while (b[j])
		{
			new[i] = b[j];
			i++;
			j++;
		}
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strndup(char *str, size_t len)
{
	char	*new;
	size_t i = 0;

	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
