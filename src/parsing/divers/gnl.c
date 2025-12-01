/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:04:39 by zmata             #+#    #+#             */
/*   Updated: 2025/12/01 12:52:09 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "cub3d.h"

int	fill_buffer(t_gnl_state *st, int fd)
{
	if (st->index_buffer >= st->nbr_octect_lu)
	{
		st->nbr_octect_lu = read(fd, st->buffer, BUFFER_SIZE);
		st->index_buffer = 0;
		if (st->nbr_octect_lu <= 0)
			return (0);
	}
	return (1);
}

int	read_chunk(t_gnl_state *st, char **line)
{
	int		start;
	char	*chunk;

	start = st->index_buffer;
	while (st->index_buffer < st->nbr_octect_lu
		&& st->buffer[st->index_buffer] != '\n')
		st->index_buffer++;
	chunk = ft_strdup_until(&st->buffer[start],
			st->index_buffer - start);
	*line = ft_strjoin(*line, chunk);
	if (st->index_buffer < st->nbr_octect_lu
		&& st->buffer[st->index_buffer] == '\n')
	{
		*line = ft_strjoin(*line, ft_strdup_until("\n", 1));
		st->index_buffer++;
		return (1);
	}
	return (0);
}

char	*get_next_linee(int fd)
{
	t_gnl_state	st;
	char		*line;
	int			status;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	st.nbr_octect_lu = 0;
	st.index_buffer = 0;
	line = NULL;
	status = 0;
	while (1)
	{
		if (!fill_buffer(&st, fd))
			return (line);
		status = read_chunk(&st, &line);
		if (status == 1)
			return (line);
	}
}
