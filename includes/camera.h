/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:28:00 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/18 19:25:54 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vec4.h"

typedef struct s_cub	t_cub;

typedef struct s_camera
{
	t_vec3	center;
	t_vec3	axis;
	double	fov_angle;
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	upper_left_corner;
	t_vec3	pixel00_loc;
	t_vec3	pixel_delta_u;
	t_vec3	pixel_delta_v;
	int		max_depth;
}	t_camera;

void	cub_init_camera(t_cub *m);

#endif
