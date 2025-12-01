/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:20:22 by ybouroga          #+#    #+#             */
/*   Updated: 2025/12/01 18:39:01 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	cub_basic_init(t_cub **m)
// {
// 	char	**map;
// 	int		y;

// 	map = ft_calloc(5 + 1, sizeof(char *));
// 	y = 0;
// 	while (y < 5)
// 		map[y++] = ft_calloc(5 + 1, sizeof(char));
// 	map[0][0] = '1'; map[0][1] = '1'; map[0][2] = '1';
//	map[0][3] = '1'; map[0][4] = '1';
// 	map[1][0] = '1'; map[1][1] = 'Y'; map[1][2] = '1';
//	map[1][3] = '1'; map[1][4] = '1';
// 	map[2][0] = '1'; map[2][1] = '0'; map[2][2] = '0';
//	map[2][3] = '0'; map[2][4] = '1';
// 	map[3][0] = '1'; map[3][1] = '0'; map[3][2] = '0';
//	map[3][3] = '0'; map[3][4] = '1';
// 	map[4][0] = '1'; map[4][1] = '1'; map[4][2] = '1';
//	map[4][3] = '1'; map[4][4] = '1';
// 	(*m)->map = map;
// 	(*m)->map_width = 5;
// 	(*m)->map_height = 5;
// 	(*m)->color_ceiling = 0x0000FF;
// 	(*m)->color_floor = 0x008000;
// 	(*m)->camera.fov_angle = ANGLE_FOV;
// 	int ys = 3;
// 	int xs = 1;
// 	(*m)->player.x = xs + C_0_5;
// 	(*m)->player.y = (*m)->map_height - 1 - ys + C_0_5;
// 	(*m)->player_dir.x = 0;
// 	(*m)->player_dir.y = 1;

// 	(*m)->file_texture[FACE_NORTH] = "test_files/fn.xpm";
// 	(*m)->file_texture[FACE_WEST] = "test_files/fw.xpm";
// 	(*m)->file_texture[FACE_SOUTH] = "test_files/fs.xpm";
// 	(*m)->file_texture[FACE_EAST] = "test_files/fe.xpm";
// }

static void	cub_init_dir_texture(t_cub **m, t_info_cub c)
{
	if (c.player.z == 'N')
	{
		(*m)->player_dir.x = 0;
		(*m)->player_dir.y = 1;
	}
	if (c.player.z == 'S')
	{
		(*m)->player_dir.x = 0;
		(*m)->player_dir.y = -1;
	}
	if (c.player.z == 'E')
	{
		(*m)->player_dir.x = 1;
		(*m)->player_dir.y = 0;
	}
	if (c.player.z == 'W')
	{
		(*m)->player_dir.x = -1;
		(*m)->player_dir.y = 0;
	}
	(*m)->file_texture[FACE_NORTH] = ft_strdup(c.nort_texture);
	(*m)->file_texture[FACE_WEST] = ft_strdup(c.west_texture);
	(*m)->file_texture[FACE_SOUTH] = ft_strdup(c.south_texture);
	(*m)->file_texture[FACE_EAST] = ft_strdup(c.east_texture);
}

static void	cub_init_map(t_cub **m, t_info_cub c)
{
	int		x;
	int		y;

	y = 0;
	while (y < (*m)->map_height)
	{
		(*m)->map[y] = ft_calloc((*m)->map_width + 1, sizeof(char));
		if ((*m)->map[y] == NULL)
		{
			free_all(&c);
			cub_exit(ERROR_CALLOC, *m);
		}
		y++;
	}
	y = 0;
	while (y < (*m)->map_height)
	{
		x = 0;
		while (x < (*m)->map_width)
		{
			(*m)->map[y][x] = c.map[y][x];
			x++;
		}
		y++;
	}
}

static void	cub_basic_init(t_cub **m, t_info_cub c)
{
	(*m)->map = ft_calloc(c.nbr_line_tab + 1, sizeof(char *));
	if ((*m)->map == NULL)
		free_all(&c);
	(*m)->map_width = 0;
	(*m)->map_height = c.nbr_line_tab;
	while (c.map[0][(*m)->map_width])
		(*m)->map_width++;
	cub_init_map(m, c);
	(*m)->color_ceiling = color_v_to_int(c.ceiling_color);
	(*m)->color_floor = color_v_to_int(c.floor_color);
	(*m)->camera.fov_angle = ANGLE_FOV;
	(*m)->player.x = c.player.x + C_0_5;
	(*m)->player.y = (*m)->map_height - 1 - c.player.y + C_0_5;
	cub_init_dir_texture(m, c);
}

void	cub_init(t_cub **m, char *filepath)
{
	t_info_cub	t_info_line;

	t_info_line = parsing(filepath);
	*m = ft_calloc(1, sizeof(t_cub));
	if (*m == NULL)
		cub_exit(ERROR_MALLOC, *m);
	cub_basic_init(m, t_info_line);
	free_all(&t_info_line);
}
