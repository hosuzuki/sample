#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int		ft_str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_str_write(char *str)
{
	while (*str)
		write(1, str++, 1);
}

char	*ft_str_n_duplicate(char *str, int n)
{
	int		i;
	char	*duplicate;

	if (!(duplicate = (char *)malloc((n + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		duplicate[i] = str[i];
		i++;
	}
	while (i < n + 1)
	{
		duplicate[i] = '\0';
		i++;
	}
	return (duplicate);
}

int	x_cmp_n_size(char *find, char *where, int n)
{
	int		i;

	i = 0;
	while (find[i] == where[i] && find[i] && n--)
		i++;
	if (find[i] != '\0')
		return (0);
	return (1);
}

int	ft_compute_score(char *find, char **strs, int strs_size)
{
	int		i;
	int		size;
	int		offset;
	int		end_offset;
	char	*str;
	int	score;
	int	curr_biggest_score;
	int	biggest_score;

	i = 0;
	biggest_score = -1;
	while (i < strs_size)
	{
		str = strs[i];
		size = ft_str_len(str);
		offset = 0;
		curr_biggest_score = -1;
		while (offset < size)
		{
			end_offset = size;
			while (end_offset > offset)
			{
				score = x_cmp_n_size(find, str + offset, end_offset - offset + 1);
				if (score > curr_biggest_score)
					curr_biggest_score += score;
				end_offset--;
			}
			offset++;
		}
		biggest_score += curr_biggest_score;
		i++;
	}
	return (biggest_score);
}

void	ft_do_on_all_comb(char **strs, int strs_size, char **copies, int *scores)
{
	int		size;
	int		offset;
	int		end_offset;
	int		jndex;

	size = ft_str_len(strs[0]);
	offset = 0;
	jndex = 0;
	while (offset < size)
	{
		end_offset = size;
		while (end_offset > offset)
		{
			copies[jndex] = ft_str_n_duplicate(strs[0] + offset, end_offset - offset);
			scores[jndex] = ft_compute_score(copies[jndex], strs + 1, strs_size - 1);
			end_offset--;
			jndex++;
		}
		offset++;
	}
}

int	ft_count_possibility(char *str)
{
	int		count;
	int		size;
	int		offset;
	int		end_offset;

	count = 0;
	size = ft_str_len(str);
	offset = 0;
	while (offset < size)
	{
		end_offset = size;
		while (end_offset-- > offset)
			count++;
		offset++;
	}
	return (count);
}

void	ft_swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void    ft_swap_str(char **a, char **b)
{
	char *c;

	c = *a;
	*a = *b;
	*b = c;
}

void	bubble_sort(int size, char **copies, int *scores)
{
	int		i;
	int		jndex;
	bool	swapped;

	i = 0;
	while (i < size)
	{
		swapped = false;
		jndex = i + 1;
		while (jndex < size)
		{
			if (scores[i] < scores[jndex])
			{
				ft_swap_int(&(scores[i]), &(scores[jndex]));
				ft_swap_str(&(copies[i]), &(copies[jndex]));
				swapped = true;
			}
			jndex++;
		}
		i++;
		if (!swapped)
			break ;
	}
}

bool	is_fitting_on_everyone(char *what, char **strs, int size)
{
	int		i;
	char	*haystack;
	char	*needle;

	if (ft_str_len(what) == 0)
		return (true);
	i = 0;
	while (i < size)
	{
		needle = what;
		haystack = strs[i];
		if (ft_str_len(haystack) != 0)
		{
			while (true)
			{
				if (*needle == '\0')
					break ;
				if (*needle == *haystack)
					needle++;
				else
					needle = what;
				if (*haystack == '\0')
					return (false);
				haystack++;
			}
		}
		i++;
	}
	return (true);
}

void	print_best(int size, char **copies, char **originals, int originals_size, int *scores)
{
	int	i;
	int	jndex;
	int	valid_score;
	int	validated;
	char	**final_copies;
	int	longest;

	i = 0;
	jndex = 0;
	validated = 0;
	valid_score = INT_MAX;
	if (!(final_copies = (char **)malloc(size * sizeof(char *))))
		return ;
	while (i < size)
	{
		if (is_fitting_on_everyone(copies[i], originals, originals_size))
		{
			if (valid_score == INT_MAX)
				valid_score = scores[i];
			if (scores[i] != valid_score)
				break ;
			final_copies[jndex] = copies[i];
			validated++;
			jndex++;
		}
		i++;
	}
	if (validated == 0)
		return ;
	i = 0;
	longest = -1;
	jndex = -1;
	while (i < validated)
	{
		if (longest < ft_str_len(final_copies[i]))
		{
			longest = ft_str_len(final_copies[i]);
			jndex = i;
		}
		i++;
	}
	if (jndex == -1)
		return ;
	ft_str_write(final_copies[jndex]);
	free(final_copies);
}

void	clear_results(int size, char **copies, int *scores)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(copies[i]);
		i++;
	}
	free(copies);
	free(scores);
}

void	ft_str_maxlenoc(char **strs, int size)
{
	int		len;
	char	**copies;
	int		*scores;

	len = ft_count_possibility(strs[0]);
	copies = (char **)malloc(len * sizeof(char *));
	scores = (int *)malloc(len * sizeof(int));
	if (!scores || !copies)
		return ;
	ft_do_on_all_comb(strs, size, copies, scores);
	bubble_sort(len, copies, scores);
	print_best(len, copies, strs + 1, size - 1, scores);
	clear_results(len, copies, scores);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		ft_str_maxlenoc(argv + 1, argc - 1);
	write(1, "\n", 1);
}
