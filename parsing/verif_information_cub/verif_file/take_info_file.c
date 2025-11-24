/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_info_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmata <zmata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:01:46 by zmata             #+#    #+#             */
/*   Updated: 2025/11/24 16:25:24 by zmata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_strdup_n(char *str, int debut, int fin)
{
	int		i;
	char	*result;

	i = 0;
	result = malloc((fin - debut + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (debut < fin && str[debut])
	{
		result[i] = str[debut];
		i++;
		debut++;
	}
	result[i] = '\0';
	return (result);
}

int	cut_space(char *str, int *index_start)
{
	while (str[*index_start]
		&& (str[*index_start] == ' ' || str[*index_start] == '\t'))
		(*index_start)++;
	return (*index_start);
}

char	*verif_empty_file(char *line, int *index_start)
{
	int		index_start_temp;
	char	*line_temp;
	int		fd;

	index_start_temp = 0;
	line_temp = NULL;
	fd = 0;
	*index_start = cut_space(line, index_start);
	index_start_temp = *index_start;
	while (line[*index_start]
		&& (line[*index_start] != ' ' && line[*index_start] != '\t'))
		(*index_start)++;
	line_temp = ft_strdup_n(line, index_start_temp, *index_start);
	fd = open(line_temp, O_RDONLY);
	if (fd == -1)
	{
		free(line_temp);
		return (NULL);
	}
	close(fd);
	return (line_temp);
}

static void	set_texture(char **texture, char *path,
			char **line, t_info_cub *t_info_line)
{
	if (*texture != NULL)
	{
		free(path);
		free(*line);
		exit_prog("Un doublon a etais repere", t_info_line);
	}
	*texture = ft_strdup(path);
}

void	take_info_file(char **line, int *who_info,
			int *index_start, t_info_cub *t_info_line)
{
	char	*path;

	*index_start = *index_start + 2;
	path = verif_empty_file(*line, index_start);
	if (!path)
	{
		free(*line);
		exit_prog("Un doublon a etais repere", t_info_line);
	}
	if (*who_info == 1)
		set_texture(&t_info_line->nort_texture, path, line, t_info_line);
	else if (*who_info == 2)
		set_texture(&t_info_line->south_texture, path, line, t_info_line);
	else if (*who_info == 3)
		set_texture(&t_info_line->west_texture, path, line, t_info_line);
	else if (*who_info == 4)
		set_texture(&t_info_line->east_texture, path, line, t_info_line);
	free(path);
}
