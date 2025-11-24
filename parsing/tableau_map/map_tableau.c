/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tableau.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmata <zmata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:01:46 by zmata             #+#    #+#             */
/*   Updated: 2025/11/24 16:35:53 by zmata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	take_in_table(t_node **liste_map, t_info_cub *t_info_line)
{
	int	which_line;

	which_line = 0;
	t_info_line->map = malloc((t_info_line->nbr_line_tab + 1) * sizeof(char *));
	if (!t_info_line->map)
	{
		free(t_info_line->map);
		exit_prog("Probleme de malloc du double tabelau", t_info_line);
	}
	t_info_line->map[t_info_line->nbr_line_tab] = NULL;
	while (which_line < t_info_line->nbr_line_tab)
	{
		t_info_line->map[which_line] = ft_strdup(
				return_line_i_to_liste(liste_map, which_line));
		if (!t_info_line->map[which_line])
		{
			free_tab(t_info_line->map);
			exit_prog("Probleme de malloc de map d une ligne du"
				" double tableau", t_info_line);
		}
		which_line++;
	}
}
