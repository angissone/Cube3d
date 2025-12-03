/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:00:57 by zmata             #+#    #+#             */
/*   Updated: 2025/12/03 14:02:32 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parsing(char *fichier_cub, t_info_cub	*t_info_line)
{
	int			fd;

	init_t_info_line(t_info_line);
	fd = open(fichier_cub, O_RDONLY);
	if (fd == -1)
		exit_prog("impossible ouvrir le fichier", t_info_line);
	parsing_loop(fd, t_info_line);
	close(fd);
	take_in_table(&t_info_line->liste_map, t_info_line);
	last_verif(t_info_line);
	check_map_closed(t_info_line);
	print_struct(t_info_line);
}
