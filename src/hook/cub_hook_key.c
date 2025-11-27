/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:42:41 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/27 15:46:08 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub_do_hook_key(t_cub *m, int keycode)
{
	if (keycode == XK_Escape)
		mlx_loop_end(m->mlx);
	if (keycode == XK_a)
		cub_move_side(m, &m->player, m->player_dir, -MOVE_STEP);
	if (keycode == XK_d)
		cub_move_side(m, &m->player, m->player_dir, MOVE_STEP);
	if (keycode == XK_w)
		cub_move_forward(m, &m->player, m->player_dir, MOVE_STEP);
	if (keycode == XK_s)
		cub_move_forward(m, &m->player, m->player_dir, -MOVE_STEP);
	if (keycode == XK_Left)
		m->player_dir = cub_rotate_xy(m, m->player_dir, -ANGLE_STEP);
	if (keycode == XK_Right)
		m->player_dir = cub_rotate_xy(m, m->player_dir, ANGLE_STEP);
	if (keycode == XK_Up)
		m->camera.fov_angle++;
	if (keycode == XK_Down)
		m->camera.fov_angle--;
	if (keycode == XK_i)
		cub_debug_camera(m);
}

void	cub_do_hook_key_2(t_cub *m)
{
	if (m->key[KEY_ESC])
		mlx_loop_end(m->mlx);
	if (m->key[KEY_A])
		cub_move_side(m, &m->player, m->player_dir, -MOVE_STEP);
	if (m->key[KEY_D])
		cub_move_side(m, &m->player, m->player_dir, MOVE_STEP);
	if (m->key[KEY_W])
		cub_move_forward(m, &m->player, m->player_dir, MOVE_STEP);
	if (m->key[KEY_S])
		cub_move_forward(m, &m->player, m->player_dir, -MOVE_STEP);
	if (m->key[KEY_LEFT])
		m->player_dir = cub_rotate_xy(m, m->player_dir, -ANGLE_STEP);
	if (m->key[KEY_RIGHT])
		m->player_dir = cub_rotate_xy(m, m->player_dir, ANGLE_STEP);
	if (m->key[KEY_UP])
		m->camera.fov_angle++;
	if (m->key[KEY_DOWN])
		m->camera.fov_angle--;
	if (m->key[KEY_I])
		cub_debug_camera(m);
}

int	get_key(int k)
{
	if (k == XK_Escape)
		return (KEY_ESC);
	else if (k == XK_a)
		return (KEY_A);
	else if (k == XK_d)
		return (KEY_D);
	else if (k == XK_w)
		return (KEY_W);
	else if (k == XK_s)
		return (KEY_S);
	else if (k == XK_Left)
		return (KEY_LEFT);
	else if (k == XK_Right)
		return (KEY_RIGHT);
	else if (k == XK_Up)
		return (KEY_UP);
	else if (k == XK_Down)
		return (KEY_DOWN);
	else if (k == XK_i)
		return (KEY_I);
	return (KEY_NONE);
}
