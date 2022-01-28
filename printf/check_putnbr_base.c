#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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

static int	ft_validate_base(char	*str)
{
	while (*str)
	{
		if (!(32 <= *str && *str <= 126))
			return (0);
		if (*str == '+' || *str == '-')
			return (0);
		if (ft_strchr(str + 1, *str) != NULL)
			return (0);
		str++;
	}
	return (1);
}

static ssize_t	ft_print_body(long	l_nbr, char	*base, int	len)
{
	static ssize_t total;
	
	total = 0;
	if (l_nbr < 0)
	{
		write(1, "-", 1);
		total++;
		ft_print_body(-l_nbr, base, len);
	}
	else
	{
		if (l_nbr >= len)
		{
			ft_print_body(l_nbr / len, base, len);
		}
		write(1, &base[l_nbr % len], 1);
		total++;
		return (total);
	}
//	return (total);
	return (-1);
}

ssize_t	ft_putnbr_base(size_t	nbr, char	*base)
{
	ssize_t	len;

	if (!ft_validate_base(base))
		return (-1);
	len = ft_strlen(base);
	if (len <= 1)
		return (-1);
	len = ft_print_body((long)nbr, base, len);
	return (len);
}

int main(void)
{
	size_t i = 12345;
 	size_t j = 10000;

	printf("\nlen is : %zu\n", ft_putnbr_base(i, "0123456789abcdef"));
	return (0);
	
}

