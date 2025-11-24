/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:20:22 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/24 17:59:29 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_basic_init(t_cub **m)
{
	int	angle;

	char **map = ft_calloc(5 + 1, sizeof(char *));
	for (int y = 0; y < 5; y++)
		map[y] = ft_calloc(5 + 1 , sizeof(char));
	map[0][0] = '1'; map[0][1] = '1'; map[0][2] = '1'; map[0][3] = '1'; map[0][4] = '1';
	map[1][0] = '1'; map[1][1] = '0'; map[1][2] = '0'; map[1][3] = '1'; map[1][4] = '1';
	map[2][0] = '1'; map[2][1] = '0'; map[2][2] = '0'; map[2][3] = '0'; map[2][4] = '1';
	map[3][0] = '1'; map[3][1] = '0'; map[3][2] = '0'; map[3][3] = '1'; map[3][4] = '1';
	map[4][0] = '1'; map[4][1] = '1'; map[4][2] = '1'; map[4][3] = '1'; map[4][4] = '1';
	(*m)->map = map;
	(*m)->map_width = 5;
	(*m)->map_height = 5;
	(*m)->color_ceiling = 0x0000FF;
	(*m)->color_floor = 0x008000;
	angle = 90;
	(*m)->camera.fov_angle = angle;
	// (*m)->camera.tan_fov = tan(degrees_to_radians(angle / 2));
	cub_print_var_d("tan", (*m)->camera.tan_fov);
	(*m)->player.x = 2;
	(*m)->player.y = 2;
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
	//cub_parser(m, filepath);
	//vec3_normalise_color((*m)->ambient.color, &(*m)->ambient.colorN);
}
