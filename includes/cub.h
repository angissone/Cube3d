/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:04:40 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/21 14:09:42 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "ray.h"
# include "camera.h"
# include "lights.h"
# include "objects.h"

typedef struct s_img {
	void	*img;
	char	*addr;
	int	 	bpp;
	int		size_line;
	int		endian;
	int		w;
	int		h;
} t_img;

typedef struct s_cub
{
	void				*mlx;
	void				*window;
	void				*image;
	void				*addr;
	int					width;
	int					height;
	int					bpp;
	int					size_line;
	int					endian;
	t_ray				ray;
	t_camera			camera;
	t_ambient_light		ambient;
	t_light				light;
	double				viewport_w;
	double				viewport_h;
	double				focal_length;
	t_sphere			*sphere;
	int					nb_sphere;
	t_plane				*plane;
	int					nb_plane;
	t_cylinder			*cylinder;
	int					nb_cylinder;
	t_hit_record		rec;
	t_interval			inter;
	unsigned int		seed;
	// int					fd_rt_file;
	// char				*rt_file_line;
	// char				**rt_file_line_tokens;
	// char				**ambient_rgb_tokens;
	// char				**camera_center_xyz_tokens;
	// char				**camera_axis_xyz_tokens;
	// char				**light_xyz_tokens;
	// char				**sphere_xyz_tokens;
	// char				**sphere_rgb_tokens;
	// char				**plane_xyz_tokens;
	// char				**plane_normal_tokens;
	// char				**plane_rgb_tokens;
	// char				**cylinder_xyz_tokens;
	// char				**cylinder_axis_tokens;
	// char				**cylinder_rgb_tokens;
	char				**map;
	int					map_width;
	int					map_height;
	int					color_floor;
	int					color_ceiling;
	t_vec2				player;
	// double				player_x;
	// double				player_y;
	t_vec2				player_dir;
	// double				player_dir_x;
	// double				player_dir_y;
	char				*file_texture[4];
	t_vec2				player_start;
	// double				player_x_start;
	// double				player_y_start;
	char				player_dir_start;
	t_img				texture[4];
}	t_cub;

#endif
