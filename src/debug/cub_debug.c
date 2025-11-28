/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:04:54 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/28 14:18:30 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_print_var_d(char *s, double n)
{
	if (DEBUG)
		printf("[%s][%7f]\n", s, n);
}

void	cub_print_vec(char *s, t_vec3 v)
{
	if (DEBUG)
		printf("[%s][%.2f,%.2f,%.2f]\n", s, v.v[0], v.v[1], v.v[2]);
}

static void	cub_print_player_dir(t_cub *m)
{
	if (m->player_dir.y > .5)
		printf("N");
	else if (m->player_dir.y < -.5)
		printf("S");
	else if (m->player_dir.x < .5)
		printf("W");
	else if (m->player_dir.x > .5)
		printf("E");
	else
		printf("X");
}

static void cub_show_map(t_cub *m)
{
	int	col;
	int	lig;

	lig = 0;
	while (lig < m->map_height)
	{
		col = 0;
		while (col < m->map_width)
		{
			if ((int)m->player.x == col && (int)m->player.y == lig)
				cub_print_player_dir(m);
			else
				printf("%c", m->map[lig][col]);
			col++;
		}
		printf("\n");
		lig++;
	}
	printf("[%d][%d][%f][%f]\n", col, lig, m->player.x, m->player.y);
}

void	cub_debug_camera(t_cub *m)
{
	t_camera	c;

	if (DEBUG)
	{
		c = m->camera;
		cub_print_var_d("width ", m->width);
		cub_print_var_d("height", m->height);
		cub_print_var_d("fov angle        ", c.fov_angle);
		cub_print_var_d("tan fov angle    ", c.tan_fov);
		cub_print_var_d("map width        ", m->map_width);
		cub_print_var_d("map height       ", m->map_height);
		cub_print_var_d("texture w        ", m->texture->w);
		cub_print_var_d("texture h        ", m->texture->h);
		cub_show_map(m);
		printf("\n");
	}
}
