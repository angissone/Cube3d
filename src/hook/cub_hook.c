/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouroga <ybouroga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:49:17 by ybouroga          #+#    #+#             */
/*   Updated: 2025/11/19 17:20:11 by ybouroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cub_hook_key(int keycode, void *param)
{
	t_cub	*m;

	m = (t_cub *)param;

	if (m->mlx)
	{
		cub_do_hook_key(m, keycode);
		//cub_init_camera(m);
	}
	return (0);
}

int	cub_mouse_hook(int buton, int x, int y, void *param)
{
	// TODO
	(void) buton;
	(void) x;
	(void) y;
	(void) param;

	return (0);
}

int	cub_render_hook(void *param)
{
	t_cub	*m;

	m = (t_cub *)param;
	m->seed = 10;
	cub_clear_window(m, COLOR_BLACK);
	cub_render(m);
	mlx_put_image_to_window(m->mlx, m->window, m->image, 0, 0);
	return (0);
}
