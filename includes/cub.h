/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:04:40 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/28 16:50:07 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "ray.h"
# include "camera.h"
# include "objects.h"
# include "parsing.h"

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		w;
	int		h;
}	t_img;

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
	double				viewport_w;
	double				viewport_h;
	double				focal_length;
	t_hit_record		rec;
	unsigned int		seed;
	char				**map;
	int					map_width;
	int					map_height;
	int					color_floor;
	int					color_ceiling;
	t_vec2				player;
	t_vec2				player_dir;
	char				*file_texture[4];
	t_vec2				player_start;
	char				player_dir_start;
	t_img				texture[4];
	t_vec2				mouse;
	int					key[256];
	t_info_cub			info_cub;
}	t_cub;

#endif
