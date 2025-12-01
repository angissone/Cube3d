/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:00:58 by ybouroga          #+#    #+#             */
/*   Updated: 2025/12/01 13:01:11 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	handle_map_line(char *line, t_info_cub *info)
{
	if (info->cmp_info < 6)
	{
		free(line);
		exit_prog("Nombre  ou ordre d information incorrect", info);
	}
	if (check_map(line, &info->liste_map) == -1)
	{
		free(line);
		exit_prog("Map non conforme", info);
	}
	new_value(line, &info->liste_map);
	info->cmp_info++;
	info->nbr_line_tab++;
}

void	handle_info_line(char *line,
			int who_info, int *index_start, t_info_cub *info)
{
	if (who_info <= 4)
	{
		take_info_file(&line, &who_info, index_start, info);
		info->cmp_info++;
	}
	else if (who_info == 5 || who_info == 6)
	{
		*index_start = cut_space(line, index_start);
		take_info_color(line, &who_info, index_start, info);
		info->cmp_info++;
	}
	else if (who_info == 7)
		handle_map_line(line, info);
}

void	process_non_empty(char *line, t_info_cub *info)
{
	int		who_info;
	int		index_start;
	char	*line_tmp;

	who_info = 0;
	index_start = 0;
	line_tmp = verif_line(line, &who_info, &index_start);
	if (!line_tmp)
	{
		free(line);
		exit_prog("impossible de trouver une des informations ou "
			"information incorrect", info);
	}
	line = line_tmp;
	handle_info_line(line, who_info, &index_start, info);
	free(line);
}

void	process_line(char *line, t_info_cub *info)
{
	if (verif_start(line) == NULL)
	{
		if (info->liste_map != NULL)
		{
			free(line);
			exit_prog("Une ligne de la map est vide", info);
		}
		free(line);
		return ;
	}
	process_non_empty(line, info);
}

void	parsing_loop(int fd, t_info_cub *info)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_linee(fd);
		if (!line)
			break ;
		line = remove_backslash_n(line);
		process_line(line, info);
	}
}
