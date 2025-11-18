/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:20:22 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/17 20:12:26 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_basic_init(t_cub **m)
{
	(void) m;
	char **map = ft_calloc(3, sizeof(char *));
	for (int y = 0; y < 3; y++)
		map[y] = ft_calloc(4, sizeof(char));
	map[0][0] = '1'; map[0][1] = '1'; map[0][2] = '1';
	map[1][0] = '1'; map[1][1] = 'N'; map[1][2] = '1';
	map[2][0] = '1'; map[2][1] = '1'; map[2][2] = '1';
	(*m)->map = map;
}

void	cub_init(t_cub **m, char *filepath)
{
	*m = ft_calloc(1, sizeof(t_cub));
	if (*m == NULL)
		cub_exit(ERROR_MALLOC, *m);
	cub_basic_init(m);
	cub_parser(m, filepath);
	vec3_normalise_color((*m)->ambient.color, &(*m)->ambient.colorN);
}
