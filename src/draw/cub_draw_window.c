/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_draw_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:54:38 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/27 15:14:19 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cub_init_fields_map(t_cub *m)
{
	cub_debug_camera(m);
}

void	cub_draw_window(t_cub *m)
{
	m->mlx = mlx_init();
	if (m->mlx == NULL)
		cub_exit(ERROR_MLX, m);
	mlx_get_screen_size(m->mlx, &m->width, &m->height);
	m->width /= SCREEN_RATIO;
	m->height /= SCREEN_RATIO;
	m->window = mlx_new_window(m->mlx, m->width, m->height, WINDOW_TITLE);
	if (m->window == NULL)
		cub_exit(ERROR_WINDOW, m);
	m->image = mlx_new_image(m->mlx, m->width, m->height);
	if (m->image == NULL)
		cub_exit(ERROR_IMAGE, m);
	m->addr = mlx_get_data_addr(m->image, &m->bpp, &m->size_line, &m->endian);
	if (m->addr == NULL)
		cub_exit(ERROR_ADDR, m);
	cub_init_texture(m);
	mlx_do_key_autorepeaton(m->mlx);
	mlx_hook(m->window, KEY_PRESS, KEY_PRESS_MASK, cub_hook_key_pressed, m);
	mlx_hook(m->window, KEY_RELEASE, 1L << 1, cub_hook_key_released, m);
	mlx_hook(m->window, MOUSE_MOUSE, 1L << 6, cub_mouse_hook, m);
	mlx_hook(m->window, ON_DESTROY, 0, cub_close_window, m);
	cub_init_fields_map(m);
	mlx_put_image_to_window(m->mlx, m->window, m->image, 0, 0);
	mlx_loop_hook(m->mlx, cub_render_hook, m);
	mlx_loop(m->mlx);
}
