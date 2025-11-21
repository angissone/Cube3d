/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:59:44 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/21 14:10:23 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_init_camera(t_cub *m, int x)
{
	double	cam_x;
	double	plane_x;
	double	plane_y;

	m->camera.tan_fov = tan(cub_degrees_to_radians(m->camera.fov_angle / 2));
	cam_x = 2 * x / (double)m->width - 1;
	plane_x = -m->player_dir.y * m->camera.tan_fov;
	plane_y = m->player_dir.x * m->camera.tan_fov;
	m->ray.origin.x = m->player.x;
	m->ray.origin.y = m->player.y;
	m->ray.dir.x = m->player_dir.x + plane_x * cam_x;
	m->ray.dir.y = m->player_dir.y + plane_y * cam_x;
}
