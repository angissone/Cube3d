/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:59:44 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/19 18:20:44 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_init_camera(t_cub *m, int x)
{
	double	cam_x;
	double	plane_x;
	double	plane_y;

	cam_x = 2 * x / (double)m->width - 1;
	plane_x = -m->player_dir_y * m->camera.tan_fov;
	plane_y = m->player_dir_x * m->camera.tan_fov;
	m->ray.origin.x = m->player_x;
	m->ray.origin.y = m->player_y;
	m->ray.dir.x = m->player_dir_x + plane_x * cam_x;
	m->ray.dir.y = m->player_dir_y + plane_y * cam_x;
}
