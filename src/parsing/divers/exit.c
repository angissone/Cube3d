/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmata <zmata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:04:31 by zmata             #+#    #+#             */
/*   Updated: 2025/11/24 16:17:34 by zmata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	writer_error(char *str)
{
	printf("Error:\n-%s\n", str);
}

void	free_all(t_info_cub *t_info_line)
{
	free(t_info_line->nort_texture);
	free(t_info_line->south_texture);
	free(t_info_line->east_texture);
	free(t_info_line->west_texture);
	free_list(t_info_line->liste_map);
	free_tab(t_info_line->map);
}

void	exit_prog(char *str, t_info_cub *t_info_line)
{
	writer_error(str);
	free_all(t_info_line);
	exit(EXIT_FAILURE);
}

void	init_t_info_line(t_info_cub *t_info_line)
{
	t_info_line->nort_texture = NULL;
	t_info_line->south_texture = NULL;
	t_info_line->east_texture = NULL;
	t_info_line->west_texture = NULL;
	t_info_line->floor_color[0] = -1;
	t_info_line->floor_color[1] = -1;
	t_info_line->floor_color[2] = -1;
	t_info_line->ceiling_color[0] = -1;
	t_info_line->ceiling_color[1] = -1;
	t_info_line->ceiling_color[2] = -1;
	t_info_line->map = NULL;
	t_info_line->cmp_info = 0;
	t_info_line->nbr_line_tab = 0;
	t_info_line->liste_map = NULL;
}

void	last_verif(t_info_cub *t_info_line)
{
	if (t_info_line->nort_texture == NULL
		|| t_info_line->south_texture == NULL)
		exit_prog("information incorrect -last_verif", t_info_line);
	if (t_info_line->east_texture == NULL
		|| t_info_line->west_texture == NULL)
		exit_prog("information incorrect -last_verif", t_info_line);
	if (t_info_line->floor_color[0] == -1
		|| t_info_line->floor_color[1] == -1
		|| t_info_line->floor_color[2] == -1)
		exit_prog("information incorrect -last_verif", t_info_line);
	if (t_info_line->ceiling_color[0] == -1
		|| t_info_line->ceiling_color[1] == -1
		|| t_info_line->ceiling_color[2] == -1)
		exit_prog("information incorrect -last_verif", t_info_line);
	if (t_info_line->map == NULL
		|| t_info_line->liste_map == NULL
		|| t_info_line->cmp_info == 0)
		exit_prog("information incorrect -last_verif", t_info_line);
}
