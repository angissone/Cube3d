#include "parsing.h"


/* ---------------- UTILS ---------------- */

int	ft_strlenn(char *s)
{
	int	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i = 0;
	int		j = 0;
	int		len = ft_strlenn(s1) + ft_strlenn(s2);
	char	*res = malloc(len + 1);
	if (!res)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	free(s2);
	return (res);
}

char	*ft_strdup_until(char *s, int n)
{
	int		i = 0;
	char	*res = malloc(n + 1);
	if (!res)
		return (NULL);
	while (i < n && s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/* ---------------- GNL ---------------- */

char	*get_next_linee(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	nbr_octect_lu = 0;
	static int	index_buffer = 0;
	char		*line = NULL;
	int			start;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (index_buffer >= nbr_octect_lu)
		{
			nbr_octect_lu = read(fd, buffer, BUFFER_SIZE);
			index_buffer = 0;
			if (nbr_octect_lu <= 0)
				return (line);
		}
		start = index_buffer;
		while (index_buffer < nbr_octect_lu && buffer[index_buffer] != '\n')
			index_buffer++;
		line = ft_strjoin(line, ft_strdup_until(&buffer[start], index_buffer - start));
		if (index_buffer < nbr_octect_lu && buffer[index_buffer] == '\n')
		{
			line = ft_strjoin(line, ft_strdup_until("\n", 1));
			index_buffer++;
			return (line);
		}
	}
}


/* int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
} */
