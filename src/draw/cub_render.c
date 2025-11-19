/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:53:25 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/19 17:57:10 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	cub_draw_v_wall(t_cub *m, int x)
{
	int	line_height;
	int	draw_begin;
	int	draw_end;
	int	y;

	line_height = (int)(m->height / m->rec.t);
	draw_begin = (m->height - line_height) / 2;
	draw_end = (m->height + line_height) / 2;

	y = 0;
	while (y < draw_begin)
		cub_putpixel(m, x, y++, m->color_ceiling);
	while (y < draw_end)
		cub_putpixel(m, x, y++, 0xff0000);
	while (y < m->height)
		cub_putpixel(m, x, y++, m->color_floor);
}

void	cub_render(t_cub *m)
{
	int		x;

	x = 0;
	while (x < m->width)
	{
		cub_init_camera(m, x);
		// cub_print_var_d("x",x);
		// cub_print_vec("o",m->ray.origin);
		// cub_print_vec("d", m->ray.dir);
		if (cub_hit_grid(m, m->ray, &m->rec))
			cub_draw_v_wall(m, x);
		x++;
		cub_putpixel(m, x, x, 0xff00ff);
	}
	// printf("Press enter...");
    //  getchar();
    // printf("[%u] go !\n", m->seed);
	//if (DEBUG) exit(0);
}
