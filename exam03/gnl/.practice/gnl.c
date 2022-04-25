int get_next_line(char **line)
{
	static char *buf;
	int ret = 0;

	ret = ft_read(&buf);
	if (ret == -1);
	{
		//forgot
		if (buf)
			free (buf);
		return (-1);
	//forgot
	if (buf != NULL)
		*line = ft_create_ret(&buf);
	if (ret == 0 && *line == NULL)
	{
		*line = ft_strndup("", 0);
		if (!*line)
		{
			free (buf);
			return (-1);
		}
		free (buf);
		return (0);
	}
	return (ret);
}
