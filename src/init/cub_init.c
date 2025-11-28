/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:20:22 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/28 18:08:43 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_basic_init(t_cub **m)
{
	char	**map;
	int		y;

	map = ft_calloc(5 + 1, sizeof(char *));
	y = 0;
	while (y < 5)
		map[y++] = ft_calloc(5 + 1, sizeof(char));
	map[0][0] = '1'; map[0][1] = '1'; map[0][2] = '1'; map[0][3] = '1'; map[0][4] = '1';
	map[1][0] = '1'; map[1][1] = '0'; map[1][2] = '1'; map[1][3] = '1'; map[1][4] = '1';
	map[2][0] = '1'; map[2][1] = '0'; map[2][2] = '0'; map[2][3] = '0'; map[2][4] = '1';
	map[3][0] = '1'; map[3][1] = '0'; map[3][2] = '0'; map[3][3] = '0'; map[3][4] = '1';
	map[4][0] = '1'; map[4][1] = '1'; map[4][2] = '1'; map[4][3] = '1'; map[4][4] = '1';
	(*m)->map = map;
	(*m)->map_width = 5;
	(*m)->map_height = 5;
	(*m)->color_ceiling = 0x0000FF;
	(*m)->color_floor = 0x008000;
	(*m)->camera.fov_angle = ANGLE_FOV;
	int ys = 3;
	int xs = 1;
	(*m)->player.x = xs + C_0_5;
	(*m)->player.y = (*m)->map_height - 1 - ys + C_0_5;
	(*m)->player_dir.x = 0;
	(*m)->player_dir.y = 1;

	(*m)->file_texture[FACE_NORTH] = "test_files/fn.xpm";
	(*m)->file_texture[FACE_WEST] = "test_files/fw.xpm";
	(*m)->file_texture[FACE_SOUTH] = "test_files/fs.xpm";
	(*m)->file_texture[FACE_EAST] = "test_files/fe.xpm";
}

void	cub_init(t_cub **m, char *filepath)
{
	*m = ft_calloc(1, sizeof(t_cub));
	if (*m == NULL)
		cub_exit(ERROR_MALLOC, *m);
	cub_basic_init(m);
	(void)filepath;
	//parsing(filepath);
	//cub_parser(m, filepath);
}
