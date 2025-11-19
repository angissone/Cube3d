/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:42:41 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/19 18:52:24 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_do_hook_key(t_cub *m, int keycode)
{
	if (keycode == XK_Escape)
		mlx_loop_end(m->mlx);
	if (keycode == XK_a || keycode == XK_Left)
		m->player_x -= MOVE_STEP;
	if (keycode == XK_d || keycode == XK_Right)
		m->player_x += MOVE_STEP;
	if (keycode == XK_w || keycode == XK_Up)
		m->player_y -= MOVE_STEP;
	if (keycode == XK_s || keycode == XK_Down)
		m->player_y += MOVE_STEP;
	if (keycode == XK_q)
		m->camera.center.v[2] -= MOVE_STEP;
	if (keycode == XK_e)
		m->camera.center.v[2] += MOVE_STEP;


		// if (keycode == XK_z)
	// 	m->t.sx -= ZOOM_STEP;
	// if (keycode == XK_x)
	// 	m->t.sx += ZOOM_STEP;
	// if (keycode == XK_c)
	// 	m->t.sy -= ZOOM_STEP;
	// if (keycode == XK_v)
	// 	m->t.sy += ZOOM_STEP;
	// if (keycode == XK_b)
	// 	m->t.sz -= ZOOM_STEP;
	// if (keycode == XK_n)
	// 	m->t.sz += ZOOM_STEP;
	// if (keycode == XK_1)
	// 	m->t.angle_z -= ANGLE_STEP_PI_20;

}