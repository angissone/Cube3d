/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:53:25 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/18 19:29:58 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_render(t_cub *m)
{
	int		x;
	int 	y;
	t_vec3	pixel_center;

	y = 0;
	while (y < m->height)
	{
		x = 0;
		while (x < m->width)
		{

			pixel_center = vec3_add(
				m->camera.pixel00_loc,
				vec3_add(
					vec3_scale(m->camera.pixel_delta_u, x),
					vec3_scale(m->camera.pixel_delta_v, y))
			);
			m->ray.dir = vec3_sub(pixel_center, m->camera.center);
			m->ray.origin = m->camera.center;
			//cub_print_var_d("MAX", m->camera.max_depth);
			cub_putpixel(m, x, y, color_to_int(ray_color(m, m->ray)));
			x++;
		}
		y++;
	}
	// printf("Press enter...");
    //  getchar();
    // printf("[%u] go !\n", m->seed);
	//if (DEBUG) exit(0);
}
