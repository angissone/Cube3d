/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmata <zmata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:04:39 by zmata             #+#    #+#             */
/*   Updated: 2025/11/24 16:19:50 by zmata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_strlenn(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	i = 0;
	j = 0;
	len = ft_strlenn(s1) + ft_strlenn(s2);
	res = malloc(len + 1);
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
	int		i;
	char	*res;

	i = 0;
	res = malloc(n + 1);
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

char	*get_next_linee(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	nbr_octect_lu = 0;
	static int	index_buffer = 0;
	char		*line;
	char		*chunk;
	int			start;

	line = NULL;
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
		chunk = ft_strdup_until(&buffer[start], index_buffer - start);
		line = ft_strjoin(line, chunk);
		if (index_buffer < nbr_octect_lu && buffer[index_buffer] == '\n')
		{
			line = ft_strjoin(line, ft_strdup_until("\n", 1));
			index_buffer++;
			return (line);
		}
	}
}
