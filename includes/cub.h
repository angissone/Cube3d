/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:04:40 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/19 15:44:34 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_H
# define MRT_H

# include "ray.h"
# include "camera.h"
# include "lights.h"
# include "objects.h"

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
	int					fd_rt_file;
	char				*rt_file_line;
	char				**rt_file_line_tokens;
	char				**ambient_rgb_tokens;
	char				**camera_center_xyz_tokens;
	char				**camera_axis_xyz_tokens;
	char				**light_xyz_tokens;
	char				**sphere_xyz_tokens;
	char				**sphere_rgb_tokens;
	char				**plane_xyz_tokens;
	char				**plane_normal_tokens;
	char				**plane_rgb_tokens;
	char				**cylinder_xyz_tokens;
	char				**cylinder_axis_tokens;
	char				**cylinder_rgb_tokens;
	char				**map;
	int					map_width;
	int					map_height;
}	t_cub;

#endif
